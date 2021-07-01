/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** menu.h
*/

#ifndef SPRITES_H_
#define SPRITES_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "text.h"
#include "game.h"

typedef struct choice {
    char *message;
    void (*fptr)();
} choice_t;

typedef struct menu_choice {
    char *message;
    sfText *text;
    sfColor color;
    sfVector2f position;
    int hover;
    struct menu_choice *next;
    void (*fptr)();
} menu_choice_t;

typedef struct menu_list {
    menu_choice_t *first;
} menu_list_t;

typedef struct options {
    char *title;
    char **choices;
    int current_choice;
    int max_choice;
    sfText *title_text;
    sfText *choice_text;
    sfVector2f position;
    sfSprite *back_arrow;
    sfSprite *next_arrow;
    int hover_left;
    int hover_right;
    void (*on_change)();
} options_t;

struct menu {
    sfSprite *logo;
    sfSprite *how_to_play;
    sfFont *font;
    sfMusic *menu_music;
    sfSound *hover;
    sfSound *select;
    sfSprite *choice_bg;
    menu_list_t *choices;
    options_t **options;
    sfSprite *back_arrow;
    sfSprite *next_arrow;
};


#endif /* !SPRITES_H_ */
