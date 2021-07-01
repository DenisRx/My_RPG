/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** xml
*/

#ifndef XML_H_
#define XML_H_

#include "game.h"

typedef struct property {
    char *name;
    char *value;
} property_t;

typedef struct tag {
    char *name;
    char *inner;
    node_t *properties;
    node_t *children;
} tag_t;

#endif /* !XML_H_ */
