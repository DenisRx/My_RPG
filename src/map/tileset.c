/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** tileset
*/

#include "global.h"

tileset_property_t *get_tileset_property(tag_t *tileset)
{
    tag_t *image = tileset->children->data;
    tileset_property_t *prop = malloc(sizeof(tileset_property_t));

    prop->width = get_property_int(image, "width", 0);
    prop->height = get_property_int(image, "height", 0);
    prop->tilewidth = get_property_int(tileset, "tilewidth", 0);
    prop->tileheight = get_property_int(tileset, "tileheight", 0);
    prop->tile_count = get_property_int(tileset, "tilecount", 0);
    prop->columns = get_property_int(tileset, "columns", 0);
    prop->path = get_property(image, "source");
    prop->path += 1;
    return (prop);
}

tileset_t *create_tileset(sfSprite *sprite, int index)
{
    tileset_t *tileset = malloc(sizeof(tileset_t));

    tileset->index = index;
    tileset->sprite = sprite;
    return (tileset);
}

sfSprite *get_sprite_tile(int i, tileset_property_t *prop)
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect = {i % prop->columns * prop->tilewidth, i / prop->columns *
        prop->tileheight, prop->tilewidth, prop->tileheight};

    texture = sfTexture_createFromFile(prop->path, &rect);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, 1);
    sfSprite_setPosition(sprite, (sfVector2f){50, 50});
    return (sprite);
}

node_t *compute_tileset(tag_t *tileset, int *index)
{
    node_t *start = malloc(sizeof(node_t));
    node_t *tmp = start;
    node_t *previous = NULL;
    tileset_property_t *prop = get_tileset_property(tileset);

    start->next = NULL;
    for (int i = 0; i < prop->tile_count; i++) {
        previous != NULL ? previous->next = tmp : (void)previous;
        tmp->data = create_tileset(get_sprite_tile(i, prop), *index);
        tmp->next = NULL;
        previous = tmp;
        tmp = malloc(sizeof(node_t));
        (*index)++;
    }
    return (start);
}

node_t *generate_tileset(tag_t *head)
{
    tag_t *map = head->children->data;
    tag_t *data;
    node_t *node = map->children;
    node_t *start = NULL;
    node_t *tmp = start;
    node_t *previous = NULL;
    int tile_index = 1;

    while (node != NULL) {
        data = node->data;
        if (my_strcmp(data->name, "tileset") == 0) {
            tmp = compute_tileset(data, &tile_index);
            previous != NULL ? previous->next = tmp : (void)previous;
            start = start == NULL ? tmp : start;
            previous = tmp;
        }
        while (previous != NULL && previous->next != NULL)
            previous = previous->next;
        node = node->next;
    }
    return (start);
}