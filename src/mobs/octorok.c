/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** octorok
*/

#include "global.h"

void is_facing_enemy(game_t *game, mob_t *mob, int mx, int my)
{
    sfFloatRect hero_rect = get_feet_rect(game);
    sfFloatRect mob_rect = sfSprite_getGlobalBounds(mob->animation->sprite);

    mob_rect.width = mx == 0 ? 10 : 9999 * mx;
    mob_rect.height = my == 0 ? 10 : 9999 * my;
    if (sfFloatRect_intersects(&hero_rect, &mob_rect, NULL) &&
    mob->projectile == NULL) {
        mob->projectile = get_animation_w_name(mob->animation_list,
        "projectile");
        mob->animation = get_animation_w_name(mob->animation_list, "shot");
        sfSprite_setPosition(mob->projectile->sprite, mob->position);
    }
    if (mob->animation == get_animation_w_name(mob->animation_list, "shot") &&
    is_animation_ended(mob->animation)) {
        mob->animation->current_frame = -1;
        mob->animation = get_animation_w_name(mob->animation_list, "idle");
    }
}

int is_sprite_ofs(sfSprite *sprite)
{
    sfVector2f pos = sfSprite_getPosition(sprite);

    if (pos.x < 0 || pos.y < 0)
        return (1);
    if (pos.x > BASE_WIDTH || pos.y > BASE_HEIGHT)
        return (1);
    return (0);
}

sfVector2f get_octorok_direction(mob_t *mob)
{
    if (mob->type == 3)
        return (sfVector2f){1, 0};
    if (mob->type == 4)
        return (sfVector2f){0, -1};
    if (mob->type == 5)
        return (sfVector2f){0, 1};
    if (mob->type == 6)
        return (sfVector2f){-1, 0};
    return (sfVector2f) {0, 0};
}

void handle_octorok(sfRenderWindow *window, game_t *game, mob_t *mob)
{
    sfVector2f direction = get_octorok_direction(mob);
    sfVector2f projectile_velocity =(sfVector2f){4 * direction.x,
        4 * direction.y};

    is_facing_enemy(game, mob, direction.x, direction.y);
    if (mob->projectile != NULL) {
        draw_animation(window, mob->projectile, game);
        sfSprite_move(mob->projectile->sprite, projectile_velocity);
        mob->velocity = projectile_velocity;
        if (is_sprite_ofs(mob->projectile->sprite)) {
            mob->projectile = NULL;
        }
    }
}
