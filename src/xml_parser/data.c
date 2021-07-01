/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** data
*/

#include "global.h"

char *get_property(tag_t *tag, char *name)
{
    property_t *property;

    for (node_t *node = tag->properties; node != NULL; node = node->next) {
        property = node->data;
        if (my_strcmp(property->name, name) == 0)
            return (property->value);
    }
    return (NULL);
}

int get_property_int(tag_t *tag, char *name, int default_value)
{
    property_t *property;

    for (node_t *node = tag->properties; node != NULL; node = node->next) {
        property = node->data;
        if (my_strcmp(property->name, name) == 0)
            return (my_getnbr(property->value));
    }
    return (default_value);
}

tag_t *get_child(tag_t *tag, char *name)
{
    tag_t *data;

    for (node_t *node = tag->children; node != NULL; node = node->next) {
        data = node->data;
        if (my_strcmp(data->name, name) == 0)
            return (data);
    }
    return (NULL);
}