/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** layer_property
*/

#include "global.h"

char *get_layer_property(layer_t *layer, char *name)
{
    property_t *property;

    for (node_t *node = layer->properties; node != NULL; node = node->next) {
        property = node->data;
        if (my_strcmp(property->name, name) == 0) {
            return (property->value);
        }
    }
    return (NULL);
}

property_t *create_property(char *name, char *value)
{
    property_t *property = malloc(sizeof(property_t));

    property->name = name;
    property->value = value;
    return (property);
}

node_t *get_layer_properties(tag_t *layer_tag)
{
    tag_t *properties = get_child(layer_tag, "properties");
    tag_t *data;
    node_t *start = malloc(sizeof(node_t));
    node_t *tmp = start;
    node_t *previous = NULL;

    if (properties == NULL) {
        free(start);
        return (NULL);
    }
    for (node_t *node = properties->children; node != NULL; node = node->next) {
        data = node->data;
        previous != NULL ? previous->next = tmp : (void)previous;
        tmp->data = create_property(get_property(data, "name"),
        get_property(data, "value"));
        tmp->next = NULL;
        previous = tmp;
        tmp = malloc(sizeof(node_t));
    }
    return (start);
}