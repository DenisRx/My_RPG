/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** mob_layer
*/

#include "game.h"
#include "xml.h"
#include "protos.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

char ***get_mob_ids(tag_t *data, mob_layer_t *layer)
{
    char **lines = my_str_to_word_array(data->inner, "\n");
    char ***ids = malloc(sizeof(char **) * (layer->height + 1));
    int i = 0;

    while (i < layer->height) {
        ids[i] = my_str_to_word_array(lines[i], ",");
        i++;
    }
    ids[i] = NULL;
    return (ids);
}

mob_layer_t *generate_mobs_layer(tag_t *head, int map_id)
{
    mob_layer_t *layer = NULL;
    node_t *tmp = ((tag_t *)head->children->data)->children;
    tag_t *data = NULL;

    while (tmp != NULL) {
        data = tmp->data;
        if (my_strcmp(data->name, "layer") == 0 &&
        get_property_int(data, "map_id", -1) == map_id) {
            layer = malloc(sizeof(mob_layer_t));
            layer->map_id = get_property_int(data, "map_id", 0);
            layer->width = get_property_int(data, "width", 0);
            layer->height = get_property_int(data, "height", 0);
            layer->ids = get_mob_ids(get_child(data, "data"), layer);
            break;
        }
        tmp = tmp->next;
    }
    return (layer);
}