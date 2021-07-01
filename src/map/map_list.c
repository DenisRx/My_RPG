/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** map_list
*/

#include "global.h"

node_t *get_map_list(char *path, game_t *game)
{
    node_t *start = malloc(sizeof(node_t));
    node_t *tmp = start;
    node_t *previous = NULL;
    tag_t *xml_head = parse_xml(path);
    tag_t *xml_maps = xml_head->children->data;
    tag_t *xml_map;
    map_t *map;

    start->next = NULL;
    for (node_t *node = xml_maps->children; node != NULL; node = node->next) {
        xml_map = node->data;
        map = generate_map(get_property(xml_map, "path"), xml_map, game);
        previous != NULL ? previous->next = tmp : (void)previous;
        tmp->data = map;
        tmp->next = NULL;
        previous = tmp;
        tmp = malloc(sizeof(node_t));
    }
    return (start);
}

map_t *get_map_from_id(game_t *game, int id)
{
    map_t *map;

    for (node_t *node = game->maps; node != NULL; node = node->next) {
        map = node->data;
        if (map->id == id)
            return (map);
    }
    return (NULL);
}