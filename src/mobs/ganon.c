/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** ganon
*/

#include "global.h"
#include <math.h>

sfVector2f get_ganon_movement(mob_t *mob)
{
    sfVector2f mob_pos = sfSprite_getPosition(mob->animation->sprite);

    return (calculate_velocity(mob_pos, mob->next_position, 10));
}

sfVector2f get_proj_movement(sfSprite *projectile, hero_t *hero)
{
    sfVector2f proj_pos = sfSprite_getPosition(projectile);
    sfVector2f hero_pos = sfSprite_getPosition(hero->animation->sprite);

    return (calculate_velocity(proj_pos, hero_pos, 15));
}

void handle_ganon_atk(mob_t *mob)
{
    if (mob->state == 7) {
        mob->animation = get_animation_w_name(mob->animation_list, "atk_start");
        sfSprite_setOrigin(mob->animation->sprite, (sfVector2f){35, 35});
        mob->state = 8;
    }
    if (mob->state == 8 && is_animation_ended(mob->animation)) {
        mob->animation = get_animation_w_name(mob->animation_list, "atk_loop");
        sfSprite_setOrigin(mob->animation->sprite, (sfVector2f){35, 35});
        mob->is_attacking = 0;
        mob->state = 9;
    }
}

void handle_ganon_proj(sfRenderWindow *window, game_t *game, mob_t *mob)
{
    if (mob->state != 9)
        return;
    draw_animation(window, mob->projectile, game);
    if (mob->projectile != NULL) {
        sfSprite_move(mob->projectile->sprite, mob->projectile->velocity);
        if (is_sprite_ofs(mob->projectile->sprite)) {
            mob->projectile = NULL;
            mob->is_attacking++;
        }
    } else {
        mob->projectile = get_animation_w_name(mob->animation_list, "proj");
        sfSprite_setPosition(mob->projectile->sprite, mob->position);
        draw_animation(window, mob->projectile, game);
        mob->projectile->velocity = get_proj_movement(mob->projectile->
        sprite, game->hero);
    }
    if (mob->is_attacking == 10) {
        mob->state = 0;
        mob->animation = get_animation_w_name(mob->animation_list, "idle");
    }
}

void handle_ganon(sfRenderWindow *window, game_t *game, mob_t *mob)
{
    if (game->cinematic->played == 0)
        return;
    if (mob->state == 0) {
        sfClock_restart(mob->movement_clock);
        mob->state = 1;
        mob->is_moving = 1;
    }
    if (mob->state == 1 &&
    sfClock_getElapsedTime(mob->idle_clock).microseconds > 1000000) {
        handle_jump_up(game, mob);
        handle_jump_down(mob);
    }
    handle_jump_start_ganon(mob);
    handle_jump_ganon(game, mob);
    handle_jump_down_ganon(mob);
    handle_stomp_ganon(window, game, mob);
    handle_ganon_atk(mob);
    handle_ganon_proj(window, game, mob);
    handle_ganon_death(window, mob, game);
    sfSprite_setPosition(mob->animation->sprite, mob->position);
}