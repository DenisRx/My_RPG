/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** godog_animation
*/

#include "global.h"
#include <math.h>

void handle_godog_animation(game_t *game, mob_t *mob)
{
    direction_t dir = BOT;
    char *anims[] = {"idle_right", "idle_bot", "idle_left", "idle_top"};
    float angle = atan2f(game->hero->position.y - mob->position.y,
    game->hero->position.x - mob->position.x) * 180 / M_PI;

    if (angle > -45 && angle < 45)
        dir = RIGHT;
    if (angle > 45 && angle < 135)
        dir = BOT;
    if (angle > 135 || angle < -135)
        dir = LEFT;
    if (angle < -45 && angle > -135)
        dir = TOP;
    mob->animation = get_animation_w_name(mob->animation_list, anims[dir]);
    center_origin_sprite(mob->animation->sprite);
    sfSprite_setPosition(mob->animation->sprite, mob->position);
}

void handle_godog_start_animation(game_t *game, mob_t *mob)
{
    direction_t dir = BOT;
    char *anims[] = {"spin_start_right", "spin_start_bot",
        "spin_start_left", "spin_start_top"};
    float angle = atan2f(game->hero->position.y - mob->position.y,
    game->hero->position.x - mob->position.x) * 180 / M_PI;

    if (angle > -45 && angle < 45)
        dir = RIGHT;
    if (angle > 45 && angle < 135)
        dir = BOT;
    if (angle > 135 || angle < -135)
        dir = LEFT;
    if (angle < -45 && angle > -135)
        dir = TOP;
    mob->animation = get_animation_w_name(mob->animation_list, anims[dir]);
    center_origin_sprite(mob->animation->sprite);
    sfSprite_setPosition(mob->animation->sprite, mob->position);
}

void handle_godog_end_animation(game_t *game, mob_t *mob)
{
    direction_t dir = BOT;
    char *anims[] = {"spin_end_right", "spin_end_bot",
        "spin_end_left", "spin_end_top"};
    float angle = atan2f(game->hero->position.y - mob->position.y,
    game->hero->position.x - mob->position.x) * 180 / M_PI;

    if (angle > -45 && angle < 45)
        dir = RIGHT;
    if (angle > 45 && angle < 135)
        dir = BOT;
    if (angle > 135 || angle < -135)
        dir = LEFT;
    if (angle < -45 && angle > -135)
        dir = TOP;
    mob->animation = get_animation_w_name(mob->animation_list, anims[dir]);
    center_origin_sprite(mob->animation->sprite);
    sfSprite_setPosition(mob->animation->sprite, mob->position);
}