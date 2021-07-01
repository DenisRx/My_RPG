/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** mob_knockback
*/

#include "global.h"

int check_sprite_collision(game_t *game, sfSprite *sprite, sfVector2f offset)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    tile_t *next_tile;

    rect.left += offset.x;
    rect.top += offset.y;
    next_tile = get_tile_at_position(game, rect);
    if (next_tile == NULL)
        return (0);
    if (next_tile->has_collision)
        return (1);
    if (has_npc_collision(game))
        return (1);
    return (next_tile->has_collision == 1);
}

void knockback_mob(game_t *game, mob_t *mob)
{
    hero_t *hero = game->hero;
    int offset_x[] = {2, 0, -2, 0};
    int offset_y[] = {0, 2, 0, -2};
    sfVector2f offset = {offset_x[hero->direction], offset_y[hero->direction]};

    if (mob->is_getting_damage && mob->knockback &&
    sfClock_getElapsedTime(mob->knockback_clock).microseconds / 7500 >= 1 &&
    check_sprite_collision(game, mob->animation->sprite, offset) == 0) {
        sfClock_restart(mob->knockback_clock);
        mob->position.x += offset.x;
        mob->position.y += offset.y;
    }
}