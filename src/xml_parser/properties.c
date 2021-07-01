/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** properties
*/

#include "global.h"

property_t *get_next_property(char **line)
{
    property_t *property = malloc(sizeof(property_t));

    property->name = get_char_until(*line, '=');
    *line += my_strlen(property->name) + 2;
    property->value = get_char_until(*line, '"');
    *line += my_strlen(property->value) + 2;
    return (property);
}

node_t *get_properties(char *line)
{
    node_t *start = malloc(sizeof(node_t));
    node_t *tmp = start;
    node_t *previous = NULL;
    property_t *property;

    start->next = NULL;
    while (line[0] != '\0' && line[0] != '>') {
        previous != NULL ? previous->next = tmp : (void)previous;
        property = get_next_property(&line);
        tmp->data = property;
        tmp->next = NULL;
        previous = tmp;
        tmp = malloc(sizeof(node_t));
    }
    return (start);
}