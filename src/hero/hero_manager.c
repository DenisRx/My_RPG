/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** hero_manager
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "global.h"

void handle_hero_damage(game_t *game)
{
    hero_t *hero = game->hero;

    if (hero->is_getting_damage && check_sprite_collision(game,
    hero->animation->sprite, hero->knockback) == 0 && game->next_map == NULL &&
    sfClock_getElapsedTime(hero->knockback_clock).microseconds > 120000) {
        sfClock_restart(hero->knockback_clock);
        hero->position.x += hero->knockback.x;
        hero->position.y += hero->knockback.y;
    }
    if (hero->is_getting_damage && is_animation_ended(hero->animation)) {
        hero->is_getting_damage = 0;
        hero->animation->current_frame = -1;
    }
}

void animate_invicibility(game_t *game)
{
    hero_t *hero = game->hero;
    sfColor color;

    if (sfClock_getElapsedTime(hero->invicibilty).microseconds < 1000000
    && sfClock_getElapsedTime(hero->invic_anim).microseconds > 100000) {
        sfClock_restart(hero->invic_anim);
        color = sfSprite_getColor(hero->animation->sprite);
        if (color.b == sfRed.b && color.g == sfRed.b && color.r == sfRed.r) {
            sfSprite_setColor(hero->animation->sprite, sfWhite);
        } else {
            sfSprite_setColor(hero->animation->sprite, sfRed);
        }
    } else {
        sfSprite_setColor(hero->animation->sprite, sfWhite);
    }
}

void change_hero_direction(game_t *game)
{
    hero_t *hero = game->hero;

    if (hero->is_attacking)
        return;
    if (hero->movement.x > 0)
        hero->direction = RIGHT;
    else if (hero->movement.y > 0)
        hero->direction = BOT;
    if (hero->movement.x < 0)
        hero->direction = LEFT;
    else if (hero->movement.y < 0 && hero->movement.x == 0)
        hero->direction = TOP;
}

void ensure_hero_idle(hero_t *hero)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyDown)
        || sfKeyboard_isKeyPressed(sfKeyRight)
        || sfKeyboard_isKeyPressed(sfKeyLeft))
        return;
    hero->is_moving = 0;
    hero->movement = (sfVector2f){0, 0};
}

void handle_hero(sfRenderWindow *window, game_t *game, tile_t *tile)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(game->hero->animation->sprite);
    int hero_y = (rect.top + rect.width) / game->map->tileheight / 2;

    if ((tile->indexes.x != 0 || tile->indexes.y != hero_y) && hero_y <
        game->map->height - 1)
        return;
    ensure_hero_idle(game->hero);
    move_hero(game);
    change_hero_direction(game);
    animate_hero(game);
    handle_hero_damage(game);
    animate_invicibility(game);
    sfSprite_setPosition(game->hero->animation->sprite, game->hero->position);
    draw_animation(window, game->hero->sword_animation, game);
    draw_animation(window, game->hero->swipe_animation, game);
    draw_animation(window, game->hero->animation, game);
    stop_attack(game);
    draw_bomb(window, game);
}