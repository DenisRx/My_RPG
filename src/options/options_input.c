/*
** EPITECH PROJECT, 2021
** myowl
** File description:
** options_input
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "global.h"

void options_click_left(sfRenderWindow* window, sfMouseButtonEvent mouse_event,
game_t *game, options_t *current_option)
{
    sfFloatRect rect;
    sfVector2i mouse_pos = (sfVector2i) {mouse_event.x, mouse_event.y};

    if (is_cursor_in_sprite(current_option->back_arrow, mouse_pos, game)) {
        if (current_option->current_choice != 0) {
            current_option->current_choice--;
            sfText_setString(current_option->choice_text,
            current_option->choices[current_option->current_choice]);
            rect = sfText_getGlobalBounds(current_option->choice_text);
            sfText_setOrigin(current_option->choice_text,
            (sfVector2f){rect.width/2, rect.height/2});
            current_option->on_change(window,
            current_option->choices[current_option->current_choice], game);
        }
    }
}

void options_click_right(sfRenderWindow* window, sfMouseButtonEvent mouse_event,
game_t *game, options_t *current_option)
{
    sfFloatRect rect;
    sfVector2i mouse_pos = (sfVector2i) {mouse_event.x, mouse_event.y};

    if (is_cursor_in_sprite(current_option->next_arrow, mouse_pos, game)) {
        if (current_option->current_choice != current_option->max_choice) {
            current_option->current_choice++;
            sfText_setString(current_option->choice_text,
            current_option->choices[current_option->current_choice]);
            rect = sfText_getGlobalBounds(current_option->choice_text);
            sfText_setOrigin(current_option->choice_text,
            (sfVector2f){rect.width/2, rect.height/2});
            current_option->on_change(window,
            current_option->choices[current_option->current_choice], game);
        }
    }
}

void handle_options_click(sfRenderWindow* window, sfEvent event,
game_t *game)
{
    sfMouseButtonEvent mouse_event = event.mouseButton;
    sfVector2i mouse_pos = (sfVector2i) {mouse_event.x, mouse_event.y};
    options_t *current_option;

    for (int i = 0; i < 5; i++) {
        current_option = game->menu->options[i];
        options_click_left(window, mouse_event, game, current_option);
        options_click_right(window, mouse_event, game, current_option);

    }
    if (is_cursor_in_sprite(game->menu->back_arrow, mouse_pos, game)) {
        game->state = START_MENU;
    }
}

int scale_on_hover(sfSprite *sprite, sfVector2i mouse_pos,
game_t *game)
{
    if (is_cursor_in_sprite(sprite, mouse_pos, game)) {
        sfSprite_setScale(sprite, (sfVector2f) {2, 2});
        return (1);
    } else {
        sfSprite_setScale(sprite, (sfVector2f) {1.5, 1.5});
    }
    return (0);
}

void handle_options_hover(__attribute__((unused))sfRenderWindow* window,
sfEvent event, game_t *game)
{
    sfMouseMoveEvent mouse_event = event.mouseMove;
    sfVector2i mouse_pos = (sfVector2i) {mouse_event.x, mouse_event.y};
    struct menu *menu = game->menu;

    for (int i = 0; i < 5; i++) {
        if (scale_on_hover(menu->options[i]->back_arrow, mouse_pos, game)) {
            play_sound(menu->options[i]->hover_left, game->menu->hover);
            menu->options[i]->hover_left = 1;
        } else {
            menu->options[i]->hover_left = 0;
        }
        if (scale_on_hover(menu->options[i]->next_arrow, mouse_pos, game)) {
            play_sound(menu->options[i]->hover_right, game->menu->hover);
            menu->options[i]->hover_right = 1;
        } else {
            menu->options[i]->hover_right = 0;
        }
    }
    scale_on_hover(menu->back_arrow, mouse_pos, game);
}