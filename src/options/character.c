/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** character
*/

#include "global.h"

void change_character(__attribute__((unused))sfRenderWindow *window, char *new,
game_t *game)
{
    enum CHARACTER_COLOR color;
    hero_t *hero = game->hero;

    if (my_strcmp(new, "GREEN") == 0)
        color = GREEN;
    if (my_strcmp(new, "BLUE") == 0)
        color = BLUE;
    if (my_strcmp(new, "PURPLE") == 0)
        color = PURPLE;
    if (my_strcmp(new, "RED") == 0)
        color = RED;
    hero->color = color;
    hero->animation_list = create_animation_list(hero_animations, color);
    hero->animation = get_animation_w_name(hero->animation_list, "idle_bot");
}