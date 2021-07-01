/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** ui.h
*/

#ifndef UI
#define UI

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "transition.h"
#include "menu.h"
#include "state.h"

typedef enum objects {
    POTION,
    BOMB,
    PARCHMENT
} type_t;

typedef struct {
    int type;
    char *name;
    sfSprite *sprite;
} object_t;

typedef struct {
    int empty;
    sfVector2f position;
    object_t *element;
} box_t;

typedef struct {
    int displayed;
    sfSprite *bg;
    sfText *title;
    sfText *level_txt;
    sfText *xp_txt;
    sfText *lives_txt;
    sfText *damage_txt;
    sfText *crit_txt;
    sfText *res_txt;
} stats_t;

#endif