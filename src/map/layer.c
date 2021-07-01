/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** layer
*/

#include "global.h"

sfSprite *get_sprite_layer(int index, map_t *map, sfVector2f indexes)
{
    sfSprite *sprite;
    tileset_t *tile;
    sfFloatRect rect;

    if (index == 0)
        return (NULL);
    for (node_t *node = map->tileset; node != NULL; node = node->next) {
        tile = node->data;
        if (tile->index == index) {
            sprite = sfSprite_copy(tile->sprite);
            break;
        }
    }
    rect = sfSprite_getGlobalBounds(sprite);
    sfSprite_setOrigin(sprite, (sfVector2f){0, rect.height - 32});
    sfSprite_setPosition(sprite, (sfVector2f){map->tilewidth * indexes.x * 2,
        map->tileheight * indexes.y * 2});
    sfSprite_setScale(sprite, (sfVector2f){2, 2});
    return (sprite);
}

tile_t *get_tile_layer(int index, map_t *map, sfVector2f indexes,
layer_t *layer)
{
    tile_t *tile;
    char *level = get_layer_property(layer, "level");

    tile = malloc(sizeof(tile_t));
    tile->level = level != NULL ? my_getnbr(level) : -1;
    tile->indexes = indexes;
    tile->has_collision = get_layer_property(layer, "collision") != NULL;
    tile->sprite = get_sprite_layer(index, map, indexes);
    return (tile);
}

node_t *compute_sprite_layers(tag_t *data, map_t *map, layer_t *layer)
{
    node_t *start = malloc(sizeof(node_t));
    node_t *tmp = start;
    node_t *previous = NULL;
    char **lines = my_str_to_word_array(data->inner, "\n");
    char **columns;

    for (int i = 0; i < layer->height; i++) {
        columns = my_str_to_word_array(lines[i], ",");
        for (int y = 0; y < layer->width; y++) {
            previous != NULL ? previous->next = tmp : (void)previous;
            tmp->data = get_tile_layer(my_getnbr(columns[y]), map,
            (sfVector2f) {y, i}, layer);
            tmp->next = NULL;
            previous = tmp;
            tmp = malloc(sizeof(node_t));
        }
    }
    return (start);
}

layer_t *generate_layer(tag_t *layer_tag, map_t *map)
{
    layer_t *layer = malloc(sizeof(layer_t));

    layer->name = get_property(layer_tag, "name");
    layer->width = get_property_int(layer_tag, "width", 0);
    layer->height = get_property_int(layer_tag, "height", 0);
    layer->properties = get_layer_properties(layer_tag);
    layer->sprites = compute_sprite_layers(get_child(layer_tag, "data"), map,
    layer);
    layer->visible = get_property_int(layer_tag, "visible", 1);
    return (layer);
}

node_t *generate_layers(tag_t *head, map_t *map)
{
    tag_t *data;
    node_t *node = ((tag_t *)head->children->data)->children;
    node_t *start = malloc(sizeof(node_t));
    node_t *tmp = start;
    node_t *previous = NULL;

    while (node != NULL) {
        data = node->data;
        if (my_strcmp(data->name, "layer") == 0) {
            previous != NULL ? previous->next = tmp : (void)previous;
            tmp->data = generate_layer(data, map);
            tmp->next = NULL;
            previous = tmp;
            tmp = malloc(sizeof(node_t));
        }
        node = node->next;
    }
    return (start);
}