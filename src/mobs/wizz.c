/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** wizz
*/

#include "global.h"

void handle_wizz_damage(game_t *game, stalactite_t *stal, mob_t *mob)
{
    sfFloatRect stal_rect = sfSprite_getGlobalBounds(stal->stalactite);
    sfFloatRect hero_rect =
    sfSprite_getGlobalBounds(game->hero->animation->sprite);

    if (stal->current != 11)
        return;
    if (sfFloatRect_intersects(&stal_rect, &hero_rect, NULL)) {
        game->hero->is_getting_damage = 1;
        if (rand() % 500 > game->hero->resistance) {
            game->hero->lives -= mob->damage;
            game->life_infos.remaining_lives -= mob->damage;
        }
        game->damage_anim->done = 0;
        game->hero->is_moving = 0;
        game->hero->movement = (sfVector2f){0, 0};
        game->hero->knockback = (sfVector2f){0, 0};
    }
    stal->current++;
}

void handle_wizz_teleport(mob_t *mob)
{
    if (mob->state == 1 &&
    sfClock_getElapsedTime(mob->movement_clock).microseconds > 4000000) {
        mob->animation = get_animation_w_name(mob->animation_list, "teleport");
        mob->state = 2;
    }
    if (mob->state == 2 && is_animation_ended(mob->animation)) {
        mob->animation = get_animation_w_name(mob->animation_list, "appear");
        mob->position.x = rand() % BASE_WIDTH;
        mob->position.y = rand() % BASE_HEIGHT;
        mob->state = 3;
    }
}

void handle_wizz(sfRenderWindow *window, game_t *game, mob_t *mob)
{
    if (mob->state == 0) {
        sfClock_restart(mob->movement_clock);
        mob->state = 1;
    }
    handle_wizz_teleport(mob);
    if (mob->state == 3 && is_animation_ended(mob->animation)) {
        mob->animation = get_animation_w_name(mob->animation_list, "cast");
        mob->misc = create_stalactite_list(mob);
        mob->state = 4;
    }
    if (mob->state == 4 && mob->animation->play_count == 3 &&
    is_animation_ended(mob->animation)) {
        mob->animation->play_count = 0;
        mob->animation = get_animation_w_name(mob->animation_list, "idle");
        mob->state = 0;
    }
    drop_stalactite(window, game, mob);
    sfSprite_setPosition(mob->animation->sprite, mob->position);
}