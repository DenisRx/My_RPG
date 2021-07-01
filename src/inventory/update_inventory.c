/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** update_inventory.c
*/

#include "global.h"

void check_inventory(game_t *game)
{
    if (game->inventory->displayed == 0 && game->stats->displayed == 0) {
        game->inventory->displayed = 1;
    }
    else
        game->inventory->displayed = 0;
}

void update_box(object_t *object_infos, box_t *box)
{
    box->empty = 1;
    box->element = object_infos;
}

void store_in_inventory(object_t *obj, game_t *game)
{
    node_t *first = game->inventory->boxes;

    for (node_t *node = first; node != NULL; node = node->next) {
        if (((box_t *)node->data)->empty == 0) {
            update_box(obj, ((box_t *)node->data));
            return;
        }
    }
}