/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** transitions
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "global.h"

void draw_bands(sfRenderWindow *window)
{
    sfRectangleShape *shape;

    shape = sfRectangleShape_create();
    sfRectangleShape_setFillColor(shape, sfBlack);
    sfRectangleShape_setSize(shape, (sfVector2f){2000, 100});
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_setPosition(shape, (sfVector2f){0, BASE_HEIGHT - 100});
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

void draw_win_msg(sfRenderWindow *window)
{
    sfText *text;
    sfFloatRect rect;

    text = create_text(sfFont_createFromFile(TITLE_FONT), 100);
    sfText_setString(text, VICTORY);
    sfText_setColor(text, sfWhite);
    sfText_setStyle(text, sfTextBold);
    rect = sfText_getGlobalBounds(text);
    sfText_setOrigin(text, (sfVector2f){rect.width/2, rect.height/2});
    sfText_setPosition(text, (sfVector2f){BASE_WIDTH/2, BASE_HEIGHT/2});
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
}

struct transiton_t *create_transition(void)
{
    struct transiton_t *transition = malloc(sizeof(struct transiton_t));

    transition->size = (sfVector2f){2000.0, 2000.0};
    transition->fade_color = sfColor_fromRGBA(0, 0, 0, 254);
    transition->time_elapsed = 0;
    transition->clock = sfClock_create();
    transition->fade = sfRectangleShape_create();
    transition->ascending = 0;
    transition->done = 0;
    sfRectangleShape_setSize(transition->fade, transition->size);
    return (transition);
}

void fade(sfRenderWindow* window, struct transiton_t *transition,
int *state)
{
    sfRectangleShape_setFillColor(transition->fade, transition->fade_color);
    sfRenderWindow_drawRectangleShape(window, transition->fade, NULL);
    if (sfClock_getElapsedTime(transition->clock).microseconds / 4000 >= 1) {
        transition->time_elapsed++;
        if (transition->ascending == 0)
            transition->fade_color.a -= 5;
        else
            transition->fade_color.a += 5;
        sfClock_restart(transition->clock);
    }
    if ((transition->ascending == 0 && transition->fade_color.a - 5 <= 0) ||
    (transition->fade_color.a + 5 >= 255 && transition->ascending)) {
        if (state != NULL)
            *state = transition->next_state;
        transition->done = 1;
    }
}