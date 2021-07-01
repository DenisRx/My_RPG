/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** transition
*/

#ifndef TRANSITION_H_
#define TRANSITION_H_

#include <SFML/Graphics.h>

struct transiton_t {
    sfVector2f size;
    sfColor fade_color;
    int time_elapsed;
    sfClock *clock;
    sfRectangleShape *fade;
    int next_state;
    int done;
    int ascending;
};

#endif /* !TRANSITION_H_ */
