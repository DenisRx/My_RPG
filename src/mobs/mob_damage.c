/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** mob_damage
*/

#include "global.h"
#include <math.h>

int is_hero_damaged(game_t *game, mob_t *mob)
{
    sfFloatRect mob_rect = sfSprite_getGlobalBounds(mob->animation->sprite);
    sfFloatRect hero_rect = get_feet_rect(game);
    sfFloatRect proj_rect;

    if (mob->projectile != NULL)
        proj_rect = sfSprite_getGlobalBounds(mob->projectile->sprite);
    if (sfFloatRect_intersects(&mob_rect, &hero_rect, NULL) &&
        game->hero->is_getting_damage == 0)
        return (1);
    if (mob->projectile != NULL &&
        sfFloatRect_intersects(&proj_rect, &hero_rect, NULL) &&
        game->hero->is_getting_damage == 0)
        return (2);
    return (0);
}

void check_hero_mob_collision(game_t *game, mob_t *mob)
{
    int damage_type;
    if (mob->is_npc)
        return;
    if ((damage_type = is_hero_damaged(game, mob)) > 0 && mob->life > 0 &&
    sfClock_getElapsedTime(game->hero->invicibilty).microseconds > 1000000) {
        sfClock_restart(game->hero->invicibilty);
        game->hero->is_getting_damage = 1;
        if (rand() % 500 > game->hero->resistance) {
            game->hero->lives -= mob->damage;
            game->life_infos.remaining_lives -= mob->damage;
        }
        game->damage_anim->done = 0;
        game->hero->is_moving = 0;
        game->hero->movement = (sfVector2f){0, 0};
        game->hero->knockback = mob->velocity;
        if (damage_type == 2) {
            mob->projectile = NULL;
        }
    }
}

void check_hero_attack(game_t *game, mob_t *mob)
{
    sfFloatRect mob_rect = sfSprite_getGlobalBounds(mob->animation->sprite);
    sfFloatRect atk_rect;

    if (game->hero->is_attacking == 0 || mob->is_npc ||
        sfClock_getElapsedTime(mob->invicibilty).microseconds / 700000 < 1)
        return;
    atk_rect = sfSprite_getGlobalBounds(game->hero->swipe_animation->sprite);
    if (sfFloatRect_intersects(&mob_rect, &atk_rect, NULL) && mob->life > 0) {
        mob->life -= (rand() % 200) < game->hero->critical_chance ?
    game->hero->damage * 2 : game->hero->damage;
        mob->is_getting_damage = 1;
        sfClock_restart(mob->invicibilty);
    }
}

void animate_mob_damage(__attribute__((unused))sfRenderWindow *window,
game_t *game, mob_t *mob)
{
    sfColor color;

    if (mob->is_getting_damage &&
    sfClock_getElapsedTime(mob->invicibilty).microseconds / 700000 < 1 &&
    sfClock_getElapsedTime(mob->dmg_clock).microseconds / 100000 >= 1) {
        sfClock_restart(mob->dmg_clock);
        color = sfSprite_getColor(mob->animation->sprite);
        if (color.b == sfRed.b && color.g == sfRed.b && color.r == sfRed.r) {
            sfSprite_setColor(mob->animation->sprite, sfWhite);
        } else {
            sfSprite_setColor(mob->animation->sprite, sfRed);
        }
    }
    if (mob->is_getting_damage &&
    sfClock_getElapsedTime(mob->invicibilty).microseconds / 700000 >= 1) {
        mob->is_getting_damage = 0;
        sfSprite_setColor(mob->animation->sprite, sfWhite);
        if (mob->life <= 0)
            handle_mob_death(game, mob);
    }
}