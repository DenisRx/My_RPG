/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** ganon_jump
*/

#include "global.h"

int check_distance(sfVector2f distance, int i)
{
    if (distance.x > -i && distance.x < i && distance.y > -i && distance.y < i)
        return (1);
    return (0);
}

void handle_jump_start_ganon(mob_t *mob)
{
    if (mob->state == 1 &&
    sfClock_getElapsedTime(mob->movement_clock).microseconds > 4000000) {
        mob->animation = get_animation_w_name(mob->animation_list,
        "jump_start");
        mob->state = 2;
    }
    if (mob->state == 2 && is_animation_ended(mob->animation)) {
        mob->gravity = 20;
        mob->animation = get_animation_w_name(mob->animation_list, "jump_loop");
        sfSprite_setOrigin(mob->animation->sprite, (sfVector2f){0, 17});
        mob->state = 3;
    }
}

void handle_jump_ganon(game_t *game, mob_t *mob)
{
    hero_t *hero = game->hero;
    sfVector2f hero_pos = sfSprite_getPosition(hero->animation->sprite);

    if (mob->state == 3) {
        mob->position.y -= mob->gravity;
        mob->gravity -= 0.4;
    }
    if (mob->state == 3 && mob->gravity < 0) {
        mob->next_position = hero_pos;
        mob->state = 4;
    }
}

void handle_jump_down_ganon(mob_t *mob)
{
    sfVector2f movement = get_ganon_movement(mob);
    sfVector2f distance = {mob->position.x - mob->next_position.x,
        mob->position.y - mob->next_position.y};

    if (mob->state == 4) {
        mob->position.x += movement.x;
        mob->position.y += movement.y;
        if (check_distance(distance, 5)) {
            mob->animation = get_animation_w_name(mob->animation_list,
            "jump_end");
            sfSprite_setOrigin(mob->animation->sprite, (sfVector2f){0, 7});
            mob->animation->play_count = 0;
            mob->state = 5;
        }
    }
    if (mob->state == 5 && is_animation_ended(mob->animation)) {
        mob->animation = get_animation_w_name(mob->animation_list, "idle");
        mob->is_moving = 0;
        mob->state = 6;
        sfClock_restart(mob->idle_clock);
    }
}

void handle_stomp_ganon(sfRenderWindow *window, game_t *game, mob_t *mob)
{
    if (mob->state == 6) {
        mob->projectile = get_animation_w_name(mob->animation_list, "stump");
        sfSprite_setPosition(mob->projectile->sprite, mob->position);
        draw_animation(window, mob->projectile, game);
        if (is_animation_ended(mob->projectile)) {
            mob->projectile = NULL;
            mob->state = 7;
        }
    }
}