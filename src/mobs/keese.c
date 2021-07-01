/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** keese
*/

#include "global.h"
#include <math.h>

void handle_keese_animation(mob_t *mob, game_t *game)
{
    direction_t dir = BOT;
    char *anims[] = {"right", "bot", "left", "top"};
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
    sfSprite_setPosition(mob->animation->sprite, mob->position);
}

void handle_keese(__attribute__((unused))sfRenderWindow *window,
game_t *game, mob_t *mob)
{
    hero_t *hero = game->hero;
    sfVector2f movement = get_movement(mob, 1);
    sfVector2f hero_pos = sfSprite_getPosition(hero->animation->sprite);

    if (sprite_in_reach(hero->animation->sprite,
    mob->animation->sprite, mob->reach)) {
        mob->is_moving = 1;
        mob->next_position = hero_pos;
        mob->velocity = movement;
    } else {
        mob->is_moving = 0;
    }
    if (mob->is_moving) {
        handle_keese_animation(mob, game);
        mob->position.x += movement.x;
        mob->position.y += movement.y;
    }
}