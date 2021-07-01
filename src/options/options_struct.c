/*
** EPITECH PROJECT, 2021
** myowl
** File description:
** options_struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "global.h"
#include "options.h"

void init_options(options_t *options, struct menu *menu, int y)
{
    options->title = (char *)options_list[y];
    options->current_choice = (int)default_options[y];
    options->max_choice = max_options[y];
    options->on_change = on_change_list[y];
    options->choices = malloc(sizeof(char *) * (options->max_choice + 1));
    for (int i = 0; i <= options->max_choice; i++) {
        options->choices[i] = (char *)options_choice_list[y][i];
    }

    options->position = (sfVector2f) {0, 0};
    options->title_text = create_text(menu->font, 20);
    options->back_arrow = sfSprite_copy(menu->back_arrow);
    options->next_arrow = sfSprite_copy(menu->next_arrow);
    options->choice_text = create_text(menu->font, 20);
    options->hover_left = 0;
    options->hover_right = 0;
}

void setup_options(options_t *options, game_t *game, int *initial_pos)
{
    sfText_setString(options->choice_text,
    options->choices[options->current_choice]);
    center_text(game, options->choice_text, 0, *initial_pos);
    center_sprite(game, options->back_arrow, 0);
    center_sprite(game, options->next_arrow, 0);
    sfSprite_setPosition(options->back_arrow,
    (sfVector2f){game->resolution.x/2 - 150,
        sfText_getPosition(options->choice_text).y + 5});
    sfSprite_setPosition(options->next_arrow,
    (sfVector2f){game->resolution.x/2 + 150,
        sfText_getPosition(options->choice_text).y + 5});
}

options_t **create_options(struct menu *menu, game_t *game)
{
    options_t **options = malloc(sizeof(options_t *) * 5);
    int offset = 40;
    sfIntRect rectangle = sfSprite_getTextureRect(menu->choice_bg);
    int initial_pos = sfSprite_getPosition(menu->choice_bg).y -
    rectangle.height/2 - 10;

    for (int y = 0; y < 5; y++) {
        options[y] = malloc(sizeof(options_t));
        init_options(options[y], menu, y);
        sfText_setString(options[y]->title_text, options[y]->title);
        center_text(game, options[y]->title_text, 0, initial_pos);
        initial_pos += 20;
        setup_options(options[y], game, &initial_pos);
        initial_pos += offset;
    }
    return (options);
}