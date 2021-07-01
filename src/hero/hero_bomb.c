/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** hero_throw
*/

#include "global.h"
#include <SFML/Graphics.h>

void handle_bomb_damage(game_t *game)
{
    bomb_t *bomb = game->hero->bomb;
    mob_t *mob = NULL;

    for (node_t *mobs = game->map->mobs; mobs->next; mobs = mobs->next) {
        mob = ((mob_t *)mobs->data);
        if (sprite_in_reach(bomb->sprite, mob->animation->sprite,
        bomb->reach)) {
            mob->life -= bomb->damage;
            mob->is_getting_damage = 1;
            sfClock_restart(mob->invicibilty);
        }
    }
}

void throw_bomb(hero_t *hero)
{
    float velocity = hero->bomb->velocity;
    float velocity_x[] = {velocity, 0, -velocity, 0};
    float velocity_y[] = {0, velocity, 0, -velocity};

    hero->bomb->is_held = 0;
    sfSprite_setPosition(hero->bomb->animation->sprite,
    sfSprite_getPosition(hero->bomb->sprite));
    sfClock_restart(hero->bomb->throw_clock);
    hero->bomb->movement = (sfVector2f){velocity_x[hero->direction],
        velocity_y[hero->direction]};
}

void draw_bomb(sfRenderWindow *window, game_t *game)
{
    bomb_t *bomb = game->hero->bomb;

    if (bomb == NULL)
        return;
    if (bomb->is_held == 1) {
        sfRenderWindow_drawSprite(window, bomb->sprite, NULL);
        return;
    }
    draw_animation(window, bomb->animation, game);
    if (is_animation_ended(bomb->animation)) {
        handle_bomb_damage(game);
        game->hero->bomb = NULL;
        return;
    }
    if (sfClock_getElapsedTime(bomb->throw_clock).microseconds > 50000) {
        sfSprite_move(bomb->animation->sprite, bomb->movement);
        sfClock_restart(bomb->throw_clock);
    }
}

bomb_t *init_bomb(void)
{
    bomb_t *bomb = malloc(sizeof(bomb_t));

    bomb->is_held = 1;
    bomb->reach = 300;
    bomb->damage = 100;
    bomb->velocity = 5;
    return (bomb);
}

bomb_t *create_bomb(hero_t *hero)
{
    bomb_t *bomb = init_bomb();
    sfVector2f scale = {2.5, 2.5};
    sfVector2f bomb_pos;
    sfFloatRect hero_bounds;

    bomb->sprite = load_sprite(BOMB_SPRITE);
    hero_bounds = sfSprite_getGlobalBounds(hero->animation->sprite);
    bomb_pos = (sfVector2f){hero_bounds.left + hero_bounds.width/2,
        hero_bounds.top};
    center_origin_sprite(bomb->sprite);
    sfSprite_setPosition(bomb->sprite, bomb_pos);
    bomb->animation = create_animation(BOMB_ANIM, 13, 1, (sfVector2f)scale);
    sfSprite_setPosition(bomb->animation->sprite,
    sfSprite_getPosition(bomb->sprite));
    bomb->throw_clock = sfClock_create();
    bomb->movement = (sfVector2f){0, 0};
    return (bomb);
}