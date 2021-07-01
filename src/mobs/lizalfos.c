/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** lizalfos
*/

#include "global.h"
#include <math.h>

void handle_lizalfos_animation(mob_t *mob, game_t *game)
{
    direction_t dir = BOT;
    char *anims[] = {"atk_right", "atk_bot", "atk_left", "atk_top"};
    float angle = atan2f(game->hero->position.y - mob->position.y,
    game->hero->position.x - mob->position.x) * 180 / M_PI;

    if (angle >= -45 && angle <= 45)
        dir = RIGHT;
    if (angle > 45 && angle < 135)
        dir = BOT;
    if (angle >= 135 || angle <= -135)
        dir = LEFT;
    if (angle < -45 && angle > -135)
        dir = TOP;
    mob->animation = get_animation_w_name(mob->animation_list, anims[dir]);
    mob->direction = dir;
    sfSprite_setPosition(mob->animation->sprite, mob->position);
}

void handle_lizalfos_idle(mob_t *mob)
{
    char *anims[] = {"idle_right", "idle_bot", "idle_left", "idle_top"};

    mob->animation = get_animation_w_name(mob->animation_list,
    anims[mob->direction]);
}

void handle_lizalfos(__attribute__((unused))sfRenderWindow *window,
game_t *game, mob_t *mob)
{
    hero_t *hero = game->hero;
    sfVector2f movement = get_movement(mob, 2);
    sfSprite *sprite = mob->animation->sprite;
    sfVector2f hero_pos = sfSprite_getPosition(hero->animation->sprite);

    if (sprite_in_reach(hero->animation->sprite, sprite, mob->reach)) {
        mob->is_moving = 1;
        mob->next_position = hero_pos;
        mob->velocity = get_movement(mob, 2);
    } else
        mob->is_moving = 0;
    if (mob->is_moving && check_sprite_collision(game, sprite, movement) == 0) {
        handle_lizalfos_animation(mob, game);
        mob->position.x += movement.x;
        mob->position.y += movement.y;
    } else
        handle_lizalfos_idle(mob);
}

void handle_enemy_type(sfRenderWindow *window, game_t *game, mob_t *mob)
{
    for (int i = 0; enemy_handlers[i].mob_type != -1; i++) {
        if (mob->type == enemy_handlers[i].mob_type)
            enemy_handlers[i].fn(window, game, mob);
    }
}