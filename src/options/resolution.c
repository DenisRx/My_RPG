/*
** EPITECH PROJECT, 2021
** Duowl
** File description:
** resolution
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "global.h"

const float ratio[] = {
    0.64,
    0.8,
    0.85375,
    1,
    1.2
};

sfFloatRect get_bounds_with_ratio(sfFloatRect bounds, float ratio)
{
    bounds.height *= ratio;
    bounds.width *= ratio;
    bounds.top *= ratio;
    bounds.left *= ratio;
    return (bounds);
}

int get_res_width(char *resolution)
{
    int nb_count = 0;
    char *str;

    while (resolution[nb_count] != 'x' && resolution[nb_count] != '\0') {
        nb_count++;
    }
    str = malloc(nb_count + 1);
    for (int i = 0; i < nb_count; i++) {
        str[i] = resolution[i];
    }
    str[nb_count] = '\0';
    return (my_getnbr(str));
}

int get_res_height(char *resolution)
{
    int start_index = 0;
    char *str;
    int i;

    while (resolution[start_index] != 'x' && resolution[start_index] != '\0') {
        start_index++;
    }
    start_index++;
    str = malloc(5);
    for (i = start_index; resolution[i] != '\0'; i++) {
        str[i - start_index] = resolution[i];
    }
    str[i] = '\0';
    return (my_getnbr(str));
}

void change_resolution(sfRenderWindow *window, char *resolution,
game_t *game)
{
    int width = get_res_width(resolution);
    int height = get_res_height(resolution);

    sfRenderWindow_setSize(window, (sfVector2u) {width, height});
    game->res_ratio = ratio[game->menu->options[0]->current_choice];
}