/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** tektite
*/

#include "global.h"

void check_attack_tektite(__attribute__((unused))sfRenderWindow *window,
game_t *game, mob_t *mob)
{
    hero_t *hero = game->hero;
    sfVector2f hero_pos = sfSprite_getPosition(hero->animation->sprite);

    if (sprite_in_reach(hero->animation->sprite, mob->animation->sprite,
    mob->reach) && mob->is_moving == 0) {
        mob->is_moving = 1;
        mob->next_position = hero_pos;
        mob->animation = get_animation_w_name(mob->animation_list, "jump");
        sfClock_restart(mob->movement_clock);
    }
}

void move_tektite(mob_t *mob)
{
    sfVector2f movement = get_movement(mob, 20);

    if (mob->is_moving &&
    sfClock_getElapsedTime(mob->movement_clock).microseconds >
    mob->animation->delay) {
        sfClock_restart(mob->movement_clock);
        mob->position.x += movement.x;
        mob->position.y += movement.y;
    }
    if (mob->is_moving && is_animation_ended(mob->animation)) {
        sfClock_restart(mob->idle_clock);
        mob->is_moving = 0;
        mob->animation->current_frame = -1;
        mob->animation = get_animation_w_name(mob->animation_list, "idle");
        sfSprite_setPosition(mob->animation->sprite, mob->position);
    }
}

void handle_tektite(sfRenderWindow *window, game_t *game, mob_t *mob)
{
    if (sfClock_getElapsedTime(mob->idle_clock).microseconds < 1000000)
        return;
    check_attack_tektite(window, game, mob);
    move_tektite(mob);
}