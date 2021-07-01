/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** menu_struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "global.h"

const choice_t choices_main[] = {
    {"START", &start_game},
    {"LOAD GAME", &load_save},
    {"HOW TO PLAY", &go_to_how_to_play},
    {"OPTIONS", &go_to_options},
    {"EXIT", &exit_game},
    {NULL, NULL}
};

const choice_t choices_pause[] = {
    {"RESUME", &resume_game},
    {"SAVE AND GO TO MAIN MENU", &go_to_main_menu},
    {"SAVE AND EXIT", &exit_save},
    {"EXIT GAME", &exit_game},
    {NULL, NULL}
};

const choice_t choices_loose[] = {
    {"GO TO MAIN MENU", &go_to_menu_no_save},
    {"EXIT GAME", &exit_game},
    {NULL, NULL}
};

menu_choice_t *create_menu_choice(char *message, sfFont *font, void
(*fptr)(sfRenderWindow *, game_t *))
{
    menu_choice_t *choice = malloc(sizeof(menu_choice_t));

    choice->message = message;
    choice->text = create_text(font, 30);
    choice->color = sfColor_fromRGBA(0, 0, 0, 255);
    choice->position = (sfVector2f) {0, 0};
    choice->hover = 0;
    choice->fptr = fptr;
    choice->next = NULL;
    sfText_setString(choice->text, message);
    return (choice);
}

void align_choices(menu_list_t *menu_list, struct menu *menu,
game_t *game, const choice_t choices[])
{
    int offset = 200 / count_choices(choices);
    sfIntRect rectangle = sfSprite_getTextureRect(menu->choice_bg);
    int initial_pos = sfSprite_getPosition(menu->choice_bg).y -
    rectangle.height/2 - 20;
    menu_choice_t *current = menu_list->first;

    initial_pos += 60;
    while (current != NULL) {
        sfText_setCharacterSize(current->text, 20);
        center_text(game, current->text, 0, initial_pos);
        initial_pos += offset;
        current = current->next;
    }
}

menu_list_t *create_menu_list(struct menu *menu, game_t *game,
const choice_t choices[])
{
    menu_list_t *menu_list = malloc(sizeof(menu_list_t));
    sfFont *font = sfFont_createFromFile(MENU_FONT);
    menu_choice_t *current_choice;

    menu_list->first = create_menu_choice(choices[0].message, font,
    choices[0].fptr);
    current_choice = menu_list->first;
    for (int i = 1; choices[i].message != NULL; i++) {
        current_choice->next = create_menu_choice(choices[i].message, font,
        choices[i].fptr);
        current_choice = current_choice->next;
    }
    align_choices(menu_list, menu, game, choices);
    return (menu_list);
}

void setup_menu(struct menu *menu, game_t *game)
{
    sfSprite_setScale(menu->choice_bg, (sfVector2f){1.5, 1.5});
    center_sprite(game, menu->choice_bg, 80);
    center_sprite(game, menu->logo, -200);
    sfSprite_setScale(menu->back_arrow, (sfVector2f){1.5, 1.5});

}

struct menu *load_menu(game_t *game, const choice_t choices[])
{
    struct menu *menu = malloc(sizeof(struct menu));

    menu->choice_bg = load_sprite(MENU_BG);
    menu->logo = load_sprite(LOGO);
    menu->font = sfFont_createFromFile(MENU_FONT);
    menu->menu_music = sfMusic_createFromFile(MENU_MUSIC);
    menu->hover = get_sound(SOUND_HOVER);
    menu->select = get_sound(SOUND_SELECT);
    menu->back_arrow = load_sprite(START_MENU_BG_ARROW);
    menu->next_arrow = load_sprite(NEXT_ARROW);
    menu->how_to_play = load_sprite(HTP_HUD);
    setup_menu(menu, game);
    menu->choices = create_menu_list(menu, game, choices);
    menu->options = create_options(menu, game);
    center_sprite(game, menu->back_arrow, -60);
    sfSprite_setPosition(menu->back_arrow,
    (sfVector2f){game->resolution.x/2 - 210,
        sfSprite_getPosition(menu->back_arrow).y});
    return (menu);
}