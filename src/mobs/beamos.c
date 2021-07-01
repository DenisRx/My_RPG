/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** beamos
*/

#include "global.h"

sfVector2f get_beam_position(mob_t *mob, int index)
{
    sfVector2f pos = mob->position;
    sfFloatRect rect = sfSprite_getGlobalBounds(mob->animation->sprite);
    sfFloatRect proj_rect = sfSprite_getGlobalBounds(mob->projectile->sprite);

    if (index == 0) {
        pos.x += rect.width / 2 - 7;
        pos.y += 25;
    }
    if (index == 1) {
        pos.x += rect.width - 7;
        pos.y += 13;
    }
    if (index == 2) {
        pos.x += rect.width / 2 - 7;
        pos.y += -proj_rect.height;
    }
    if (index == 3) {
        pos.y += 13;
        pos.x += -proj_rect.width;
    }
    return (pos);
}

sfVector2f get_eye_position(mob_t *mob, int index)
{
    sfVector2f pos = mob->position;
    sfFloatRect rect = sfSprite_getGlobalBounds(mob->animation->sprite);

    if (index == 0) {
        pos.x += rect.width / 2;
        pos.y += 25;
    }
    if (index == 1) {
        pos.x += rect.width - 10;
        pos.y += 13;
    }
    if (index == 2) {
        pos.x += rect.width / 2;
    }
    if (index == 3) {
        pos.y += 15;
    }
    return (pos);
}

sfVector2f get_impact_position(mob_t *mob, int index)
{
    sfVector2f pos = mob->position;
    sfFloatRect rect = sfSprite_getGlobalBounds(mob->animation->sprite);
    sfFloatRect proj_rect = sfSprite_getGlobalBounds(mob->projectile->sprite);

    if (index == 0) {
        pos.x += rect.width / 2;
        pos.y += proj_rect.height;
    }
    if (index == 1) {
        pos.x += rect.width + proj_rect.width;
        pos.y += 15;
    }
    if (index == 2) {
        pos.x += rect.width / 2;
        pos.y += -proj_rect.height;
    }
    if (index == 3) {
        pos.y += 13;
        pos.x += -proj_rect.width;
    }
    return (pos);
}

void animate_beam(sfRenderWindow *window, game_t *game, mob_t *mob, int index)
{
    animation_t *effect = get_animation_w_name(mob->animation_list,
    "beam_effect");
    animation_t *impact = get_animation_w_name(mob->animation_list,
    "beam_impact");

    if (mob->projectile == NULL)
        return;
    center_origin_sprite(effect->sprite);
    center_origin_sprite(impact->sprite);
    sfSprite_setPosition(impact->sprite, get_impact_position(mob, index));
    sfSprite_setPosition(effect->sprite, get_eye_position(mob, index));
    sfRenderWindow_drawSprite(window, mob->projectile->sprite, NULL);
    draw_animation(window, effect, game);
    draw_animation(window, impact, game);
    if (is_animation_ended(effect)) {
        mob->projectile = NULL;
        mob->animation->pause = 0;
        sfClock_restart(mob->idle_clock);
    }
}

void handle_beamos(sfRenderWindow *window, game_t *game, mob_t *mob)
{
    sfFloatRect hero_rect = get_feet_rect(game);
    sfFloatRect mob_rect = sfSprite_getGlobalBounds(mob->animation->sprite);
    char *beams[] = {"beam_bot", "beam_right", "beam_top", "beam_left"};
    int mx[] = {0, 1, 0, -1};
    int my[] = {1, 0, -1, 0};
    int index = mob->animation->current_frame;

    mob_rect.left += (mx[index] != 0) ? mob_rect.width / 2 - 7 : 0;
    mob_rect.width = mx[index] == 0 ? 50 : 300 * mx[index];
    mob_rect.height = my[index] == 0 ? 50 : 300 * my[index];
    if (sfFloatRect_intersects(&hero_rect, &mob_rect, NULL) &&
    sfClock_getElapsedTime(mob->idle_clock).microseconds > 2000000) {
        mob->animation->pause = 1;
        mob->projectile = get_animation_w_name(mob->animation_list,
        beams[index]);
        sfSprite_setPosition(mob->projectile->sprite,
        get_beam_position(mob, index));
        mob->velocity.x = 10 * mx[index];
        mob->velocity.y = 10 * my[index];
    }
    animate_beam(window, game, mob, index);
}