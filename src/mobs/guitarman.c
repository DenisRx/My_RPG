/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** guitarman
*/

#include "global.h"

void handle_guitar_attack(game_t *game, mob_t *mob)
{
    sfFloatRect mob_rect = sfSprite_getGlobalBounds(mob->animation->sprite);

    if (sprite_in_reach(mob->animation->sprite, game->hero->animation->sprite,
    220) && sfClock_getElapsedTime(mob->idle_clock).microseconds > 3000000) {
        mob->is_attacking = 1;
        mob->projectile = get_animation_w_name(mob->animation_list,
        "projectile");
        center_origin_sprite(mob->projectile->sprite);
        sfSprite_setPosition(mob->projectile->sprite, (sfVector2f){
            mob_rect.left + mob_rect.width / 2,
            mob_rect.top + mob_rect.height / 2});
        mob->animation = get_animation_w_name(mob->animation_list, "flame");
    }
}

void handle_guitar_projectile(sfRenderWindow *window, game_t *game, mob_t *mob)
{
    if (mob->projectile != NULL) {
        draw_animation(window, mob->projectile, game);
        if (is_animation_ended(mob->projectile)) {
            mob->projectile = NULL;
            mob->is_attacking = 0;
            mob->animation = get_animation_w_name(mob->animation_list, "idle");
            sfClock_restart(mob->idle_clock);
        }
    }
}

void handle_guitar_boss(sfRenderWindow *window, game_t *game, mob_t *mob)
{
    handle_jump_up(game, mob);
    handle_jump_down(mob);
    handle_guitar_attack(game, mob);
    handle_guitar_projectile(window, game, mob);
}