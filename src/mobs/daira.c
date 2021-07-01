/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** daira
*/

#include "global.h"
#include <math.h>

void handle_daira_animation(mob_t *mob, game_t *game)
{
    direction_t dir = BOT;
    char *anims[] = {"atk_right", "atk_bot", "atk_left", "atk_top"};
    float angle = atan2f(game->hero->position.y - mob->position.y,
    game->hero->position.x - mob->position.x) * 180 / M_PI;
    sfVector2f origin_list[] = {{0, 0}, {0, 0}, {64, 0}, {0, 64}};

    if (angle > -45 && angle < 45)
        dir = RIGHT;
    if (angle > 45 && angle < 135)
        dir = BOT;
    if (angle > 135 || angle < -135)
        dir = LEFT;
    if (angle < -45 && angle > -135)
        dir = TOP;
    mob->animation = get_animation_w_name(mob->animation_list, anims[dir]);
    sfSprite_setOrigin(mob->animation->sprite, origin_list[dir]);
    mob->direction = dir;
}

void handle_daira_idle(mob_t *mob, game_t *game)
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

    mob->animation = get_animation_w_name(mob->animation_list,
    anims[dir]);
}

void handle_atk_daira(mob_t *mob, game_t *game)
{
    if (mob->is_attacking && is_animation_ended(mob->animation)) {
        sfClock_restart(mob->idle_clock);
        mob->is_attacking = 0;
        mob->animation->current_frame = -1;
    } else if (mob->is_attacking == 0)
        handle_daira_idle(mob, game);
}

void handle_daira(__attribute__((unused))sfRenderWindow *window, game_t *game,
mob_t *mob)
{
    hero_t *hero = game->hero;
    sfVector2f hero_pos = sfSprite_getPosition(hero->animation->sprite);

    handle_jump_up(game, mob);
    handle_jump_down(mob);
    if (sprite_in_reach(hero->animation->sprite,
    mob->animation->sprite, mob->reach) && mob->is_attacking == 0 &&
    sfClock_getElapsedTime(mob->idle_clock).microseconds > 2000000) {
        mob->is_attacking = 1;
        mob->next_position = hero_pos;
        mob->velocity = get_movement(mob, 1);
        handle_daira_animation(mob, game);
    }
    handle_atk_daira(mob, game);
}