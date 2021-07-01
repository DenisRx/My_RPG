/*
** EPITECH PROJECT, 2021
** my_owl
** File description:
** fps
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "global.h"

void change_fps(sfRenderWindow *window, char *new_value,
__attribute__((unused))game_t *game)
{
    sfRenderWindow_setFramerateLimit(window, my_getnbr(new_value));
}