/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** event_inventory.c
*/

#include "global.h"

const use_event use_item[NB_TYPES] = {&add_life, &hold_bomb, &raise_xp};

void display_boxes(sfRenderWindow *window, node_t *first)
{
    for (node_t *node = first; node != NULL; node = node->next) {
        if (((box_t *)node->data)->empty) {
            sfSprite_setPosition(((box_t *)node->data)->element->sprite,
            ((box_t *)node->data)->position);
            sfRenderWindow_drawSprite(window,
            ((box_t *)node->data)->element->sprite, NULL);
        }
    }
}

void handle_inventory(sfRenderWindow *window, game_t *game)
{
    if (game->inventory->displayed == 1) {
        sfRenderWindow_drawSprite(window, game->inventory->sprite, NULL);
        sfRenderWindow_drawText(window, game->inventory->title, NULL);
        display_boxes(window, game->inventory->boxes);
    }
}

void display_inventory(__attribute__((unused))sfRenderWindow *window,
sfEvent event, game_t *game)
{
    if (event.key.code == sfKeyI) {
        check_inventory(game);
        game->hero->movement = (sfVector2f){0, 0};
        game->hero->is_moving = 0;
    }
}

void click_inventory(__attribute__((unused))sfRenderWindow *window,
sfEvent event, game_t *game)
{
    sfMouseButtonEvent mouse_evt = event.mouseButton;
    sfFloatRect sprite_bounds;
    sfFloatRect def = {0, 0, 0, 0};

    if (game->inventory->displayed != 1 || mouse_evt.button != sfMouseLeft)
        return;
    for (node_t *node = game->inventory->boxes; node != NULL;
    node = node->next) {
        sprite_bounds = ((box_t *)node->data)->element != NULL ?
    sfSprite_getGlobalBounds(((box_t *)node->data)->element->sprite) : def;
        sprite_bounds = get_bounds_with_ratio(sprite_bounds, game->res_ratio);
        if (sfFloatRect_contains(&sprite_bounds, mouse_evt.x, mouse_evt.y)) {
            use_item[((box_t *)node->data)->element->type](game, node);
            game->inventory->remaining += 1;
        }
    }
}

void handle_full_inventory(__attribute__((unused))sfRenderWindow *window,
game_t *game)
{
    inv_msg_t *inv = game->inventory->inv_msg;

    display_dialog(game, inv->msg_bg, inv->full_inv_err, 3000000);
}

