/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** map
*/

#include "global.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

void set_mobs_position(map_t *map)
{
    mob_t *mob;

    if (map->mobs == NULL)
        return;
    for (node_t *node = map->mobs; node->next != NULL; node = node->next) {
        mob = node->data;
        sfSprite_setPosition(mob->animation->sprite, (sfVector2f) {
            mob->start_indexes.y * map->tilewidth * 2,
            mob->start_indexes.x * map->tileheight * 2
        });
        mob->position = sfSprite_getPosition(mob->animation->sprite);
    }
}

void init_map(map_t *map, tag_t *xml_map)
{
    map->music_id = get_property_int(xml_map, "music_id", -1);
    map->music_path = get_property(xml_map, "music_path");
    map->top = get_property_int(xml_map, "top", -1);
    map->left = get_property_int(xml_map, "left", -1);
    map->right = get_property_int(xml_map, "right", -1);
    map->bot = get_property_int(xml_map, "bot", -1);
    map->id = get_property_int(xml_map, "id", -1);
    map->tag = xml_map;
}

map_t *generate_map(char *filepath, tag_t *xml_map, game_t *game)
{
    map_t *map = malloc(sizeof(map_t));
    tag_t *xml_head = parse_xml(filepath);
    tag_t *map_tag = xml_head->children->data;

    my_printf("Loading map : %s\n", filepath);
    show_loading_screen(game->window);
    init_map(map, xml_map);
    map->tileheight = get_property_int(map_tag, "tileheight", 0);
    map->tilewidth = get_property_int(map_tag, "tilewidth", 0);
    map->width = get_property_int(map_tag, "width", 0);
    map->height = get_property_int(map_tag, "height", 0);
    map->tileset = generate_tileset(xml_head);
    map->layers = generate_layers(xml_head, map);
    map->objects = NULL;
    map->mobs = generate_mobs(map->id, game);
    set_mobs_position(map);
    return (map);
}