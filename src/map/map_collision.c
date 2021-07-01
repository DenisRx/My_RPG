/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** map_collision
*/

#include "global.h"

tile_t *check_layers_at_position(layer_t *layer, sfFloatRect at)
{
    tile_t *tile_data = NULL;
    tile_t *result = NULL;
    sfFloatRect rect;

    for (node_t *tile_node = layer->sprites; tile_node != NULL;
    tile_node = tile_node->next) {
        tile_data = tile_node->data;
        if (tile_data->sprite != NULL) {
            rect = sfSprite_getGlobalBounds(tile_data->sprite);
            result = (tile_data->level != -1 || tile_data->has_collision) &&
            sfFloatRect_intersects(&at, &rect, NULL) ? tile_data : result;
        }
    }
    return (result);
}

tile_t *get_tile_at_position(game_t *game, sfFloatRect at)
{
    node_t *node = game->map->layers;
    layer_t *data = NULL;
    tile_t *result = NULL;
    tile_t *return_value = NULL;

    while (node != NULL) {
        data = node->data;
        result = check_layers_at_position(data, at);
        return_value = result != NULL ? result : return_value;
        node = node->next;
    }
    return (return_value);
}