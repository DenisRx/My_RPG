/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** godog
*/

#include "global.h"
#include <math.h>

void godog_attack(game_t *game, mob_t *mob)
{
    if (sprite_in_reach(mob->animation->sprite, game->hero->animation->sprite,
    700) && sfClock_getElapsedTime(mob->idle_clock).microseconds > 3000000
    && mob->is_attacking == 0) {
        mob->is_attacking = 1;
        mob->state = 1;
        handle_godog_start_animation(game, mob);
        center_origin_sprite(mob->animation->sprite);
        sfSprite_setPosition(mob->animation->sprite, mob->position);
    }
    if (mob->is_attacking && mob->state == 3 &&
    is_animation_ended(mob->animation)) {
        mob->is_attacking = 0;
        mob->animation->current_frame = -1;
        sfClock_restart(mob->idle_clock);
        handle_godog_animation(game, mob);
        mob->state = 0;
        mob->jump_down = 0;
        mob->current_jump = (sfVector2f) {0, 0};
    }
}

void start_spin_godog(game_t *game, mob_t *mob)
{
    if (mob->is_attacking && mob->state == 1 &&
    is_animation_ended(mob->animation)) {
        mob->animation = get_animation_w_name(mob->animation_list, "spin");
        center_origin_sprite(mob->animation->sprite);
        sfSprite_setPosition(mob->animation->sprite, mob->position);
        mob->next_position = game->hero->position;
        sfClock_restart(mob->movement_clock);
        mob->state = 2;
    }
}

void handle_godog_attack(game_t *game, mob_t *mob)
{
    sfVector2f movement = get_movement(mob, 3);
    sfVector2f distance = {mob->position.x - mob->next_position.x,
        mob->position.y - mob->next_position.y};

    godog_attack(game, mob);
    start_spin_godog(game, mob);
    if (mob->is_attacking && mob->state == 2) {
        mob->position.x += movement.x * 2;
        mob->position.y += movement.y * 2;
        if (distance.x > -5 && distance.x < 5 &&
        distance.y > -5 && distance.y < 5) {
            mob->animation->current_frame = -1;
            handle_godog_end_animation(game, mob);
            mob->state = 3;
        }
    }
}

void handle_godog(__attribute__((unused))sfRenderWindow *window, game_t *game,
mob_t *mob)
{
    if (mob->jump_down == 0 && mob->is_attacking == 0) {
        handle_godog_animation(game, mob);
    }
    handle_jump_up(game, mob);
    handle_jump_down(mob);
    handle_godog_attack(game, mob);
}