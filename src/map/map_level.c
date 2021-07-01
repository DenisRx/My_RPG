/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** map_level
*/

#include "global.h"

int get_level(game_t *game, sfFloatRect at)
{
    tile_t *tile = get_tile_at_position(game, at);

    if (tile == NULL)
        return (-1);
    return (tile->level);
}