/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** mobs_manager
*/

#include "global.h"
#include <math.h>

void handle_ganon(sfRenderWindow *window, game_t *game, mob_t *mob);

const enemy_handler_t enemy_handlers[] = {
    {3, &handle_octorok},
    {4, &handle_octorok},
    {5, &handle_octorok},
    {6, &handle_octorok},
    {7, &handle_tektite},
    {8, &handle_beamos},
    {9, &handle_keese},
    {10, &handle_lizalfos},
    {12, &handle_daira},
    {13, &handle_guitar_boss},
    {14, &handle_godog},
    {15, &handle_wizz},
    {16, &handle_ganon},
    {-1, NULL}
};

float get_hero_distance(sfVector2f hero_mid_pos, sfVector2f mob_mid_pos)
{
    float distance = sqrt(pow(mob_mid_pos.y - hero_mid_pos.y, 2) +
    pow(mob_mid_pos.x - hero_mid_pos.x, 2));

    return (distance);
}

sfVector2f get_movement(mob_t *mob, int c)
{
    sfVector2f mob_pos = sfSprite_getPosition(mob->animation->sprite);

    return (calculate_velocity(mob_pos, mob->next_position, c));
}

void handle_mob(sfRenderWindow *window, game_t *game, mob_t *mob, tile_t *tile)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(mob->animation->sprite);
    int index_y = (rect.top + rect.width) / game->map->tileheight / 2;

    if (tile->indexes.x != 0 || (tile->indexes.y != index_y && index_y <= 14 &&
        index_y > 0) || (index_y > 14 && tile->indexes.y < 14) ||
        (index_y <= 0 && tile->indexes.y != 0))
        return;
    if (mob->displayed) {
        draw_animation(window, mob->animation, game);
        sfSprite_setPosition(mob->animation->sprite, mob->position);
        check_hero_mob_collision(game, mob);
        check_hero_attack(game, mob);
        knockback_mob(game, mob);
        animate_mob_damage(window, game, mob);
        handle_enemy_type(window, game, mob);
    } else if (is_animation_ended(mob->dying_animation)) {
        sfSprite_setPosition(mob->dying_animation->sprite, mob->position);
        draw_animation(window, mob->dying_animation, game);
    }
}

void handle_mobs(sfRenderWindow *window, game_t *game, tile_t *tile)
{
    mob_t *mob;
    map_t *map = game->map;

    if (map->mobs == NULL || game->next_map != NULL)
        return;
    for (node_t *node = map->mobs; node->next != NULL; node = node->next) {
        mob = node->data;
        handle_mob(window, game, mob, tile);
    }
}

void move_maps_mobs(map_t *map, sfVector2f offset)
{
    mob_t *mob;

    if (map->mobs == NULL)
        return;
    for (node_t *node = map->mobs; node->next != NULL; node = node->next) {
        mob = node->data;
        mob->position.x += offset.x;
        mob->position.y += offset.y;
    }
}