/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** menu_input
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "global.h"

const sfVector2f menu_bg_pos = { MENU_BG_X, MENU_BG_Y };

sfBool is_cursor_in_sprite(sfSprite *sprite, sfVector2i mouse_pos,
game_t *game)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

    rect = get_bounds_with_ratio(rect, game->res_ratio);
    return (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y));
}

sfBool is_cursor_in_text(sfText *text, sfVector2i mouse_pos,
game_t *game)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);

    rect = get_bounds_with_ratio(rect, game->res_ratio);
    return (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y));
}

void handle_menu_click(sfRenderWindow* window, sfEvent event,
game_t *game)
{
    sfMouseButtonEvent mouse_event = event.mouseButton;
    struct menu *menu = game->menu;
    menu_choice_t *current = menu->choices->first;
    sfVector2i mouse_pos = (sfVector2i) {mouse_event.x, mouse_event.y};

    while (current != NULL) {
        if (is_cursor_in_text(current->text, mouse_pos, game)) {
            sfSound_play(game->menu->select);
            sfText_setFillColor(current->text,
            sfColor_fromRGBA(53, 184, 33, 255));
            show_game(window, game);
            sfRenderWindow_display(window);
            sfSleep(sfMilliseconds(100));
            current->fptr(window, game);
            sfText_setFillColor(current->text, sfBlack);
        }
        current = current->next;
    }
}

void play_sound(int already_played, sfSound *sound)
{
    if (already_played == 0)
        sfSound_play(sound);
}

void handle_hover(sfRenderWindow* window, game_t *game,
struct menu *menu)
{
    menu_choice_t *current = menu->choices->first;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    while (current != NULL) {
        if (is_cursor_in_text(current->text, mouse_pos, game)) {
            play_sound(current->hover, menu->hover);
            current->hover = 1;
            sfText_setStyle(current->text, sfTextBold | sfTextUnderlined);
        } else {
            sfText_setStyle(current->text, sfTextRegular);
            current->hover = 0;
        }
        current = current->next;
    }
}