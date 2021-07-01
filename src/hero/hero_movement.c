/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** hero_input
*/

#include "game.h"
#include "protos.h"

void move_held_bomb(hero_t *hero)
{
    sfFloatRect hero_bounds;
    sfVector2f bomb_pos;

    if (hero->bomb == NULL)
        return;
    if (hero->bomb->is_held == 0)
        return;
    hero_bounds = sfSprite_getGlobalBounds(hero->animation->sprite);
    bomb_pos = (sfVector2f){hero_bounds.left + hero_bounds.width/2,
        hero_bounds.top};
    sfSprite_setPosition(hero->bomb->sprite, bomb_pos);
}

void move_hero(game_t *game)
{
    int next_level;
    int current_level;
    hero_t *hero = game->hero;

    if (game->win == 1)
        return;
    if (hero->is_moving && !hero->is_attacking && !hero->is_getting_damage
    && sfClock_getElapsedTime(hero->movement_clock).microseconds / 15000
    >= 1) {
        sfClock_restart(hero->movement_clock);
        current_level = get_current_level(game);
        next_level = get_next_level(game, current_level);
        if (next_level != current_level && current_level != -2 && next_level
            != -2 && next_level != -1)
            return;
        if (next_tile_has_collision(game))
            return;
        hero->position.x += hero->movement.x;
        hero->position.y += hero->movement.y;
        move_held_bomb(hero);
    }
}

void move_key_release(__attribute__((unused))sfRenderWindow *window,
sfEvent event, game_t *game)
{
    int speed = game->hero->speed;
    int mov_x[] = {0, speed, 0, -speed};
    int mov_y[] = {-speed, 0, speed, 0};
    int directions[] = {sfKeyUp, sfKeyRight, sfKeyDown, sfKeyLeft, -1};

    if (game->hero->is_moving == 0)
        return;
    for (int i = 0; directions[i] != -1; i++) {
        if (event.key.code == directions[i]) {
            game->hero->movement.x -= mov_x[i];
            game->hero->movement.y -= mov_y[i];
            game->hero->is_moving =
            game->hero->movement.x == 0 && game->hero->movement.y == 0 ? 0 : 1;
        }
    }
}

void move_key_press(__attribute__((unused))sfRenderWindow *window,
sfEvent event, game_t *game)
{
    int speed = game->hero->speed;
    int mov_x[] = {0, speed, 0, -speed};
    int mov_y[] = {-speed, 0, speed, 0};
    int directions[] = {sfKeyUp, sfKeyRight, sfKeyDown, sfKeyLeft, -1};

    if (game->next_map != NULL || game->inventory->displayed ||
        game->stats->displayed || game->paused
        || (game->dialog->displayed == 1 && game->dialog->delay == 0)
        || game->life_infos.remaining_lives == 0)
        return;
    for (int i = 0; directions[i] != -1; i++) {
        if (event.key.code == directions[i]) {
            game->hero->is_moving = 1;
            game->hero->movement.x += mov_x[i];
            game->hero->movement.y += mov_y[i];
        }
    }
}

void move_lost_focus(__attribute__((unused))sfRenderWindow *window,
__attribute__((unused))sfEvent event, game_t *game)
{
    game->hero->movement.x = 0;
    game->hero->movement.y = 0;
    game->hero->is_moving = 0;
}