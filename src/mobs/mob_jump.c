/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** mob_jump
*/

#include "global.h"
#include <math.h>

sfVector2f calculate_velocity(sfVector2f initial_po, sfVector2f dist_pos,
int c)
{
    sfVector2f velocity = {0, 0};
    float angle = atan2f(initial_po.y - dist_pos.y, initial_po.x - dist_pos.x);

    velocity.x = -(cos(angle) * c);
    velocity.y = -(sin(angle) * c);
    return (velocity);
}

void handle_jump_up(game_t *game, mob_t *mob)
{
    hero_t *hero = game->hero;
    sfVector2f hero_pos = sfSprite_getPosition(hero->animation->sprite);

    if (mob->jump_down == 0 && mob->is_attacking == 0 &&
    sfClock_getElapsedTime(mob->jump_clock).microseconds > 20000) {
        sfClock_restart(mob->jump_clock);
        mob->position.y -= mob->gravity;
        mob->gravity -= 0.4;
        if (mob->gravity <= 0) {
            mob->jump_down = 1;
            mob->next_position = hero_pos;
        }
    }
}

void handle_jump_down(mob_t *mob)
{
    sfVector2f movement = get_movement(mob, 2);

    if (mob->jump_down && mob->is_attacking == 0 &&
    sfClock_getElapsedTime(mob->jump_clock).microseconds > 10000) {
        sfClock_restart(mob->jump_clock);
        mob->position.y -= mob->gravity;
        mob->gravity -= 0.4;
        mob->position.x += movement.x * 4;
        mob->position.y += movement.y < 0 ? movement.y * 4 : movement.y * 2;
        if (mob->gravity <= -5) {
            mob->jump_down = 0;
            mob->gravity = 5;
        }
    }
}