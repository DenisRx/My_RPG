/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** hero_spawn
*/

#include "global.h"

sfVector2f find_spawn(layer_t *layer)
{
    for (node_t *node = layer->sprites; node != NULL; node = node->next) {
        if (((tile_t *)node->data)->sprite != NULL) {
            return (sfSprite_getPosition(((tile_t *)node->data)->sprite));
        }
    }
    return (sfVector2f) {0, 0};
}

sfVector2f get_player_spawn(game_t *game)
{
    layer_t *data;

    for (node_t *node = game->map->layers; node != NULL; node = node->next) {
        data = node->data;
        if (get_layer_property(data, "spawn") != NULL) {
            return (find_spawn(data));
        }
    }
    return (sfVector2f) {0, 0};
}