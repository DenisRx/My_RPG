/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** hero_collision
*/

#include "global.h"

sfFloatRect get_feet_rect(game_t *game)
{
    hero_t *hero = game->hero;
    sfFloatRect rect = sfSprite_getGlobalBounds(hero->animation->sprite);

    rect.height = 32;
    rect.width = 56;
    rect.top += 40;
    return (rect);
}

int has_npc_collision(game_t *game)
{
    sfFloatRect feet_rect = get_feet_rect(game);
    sfFloatRect rect;

    feet_rect.left += game->hero->movement.x;
    feet_rect.top += game->hero->movement.y;
    if (game->map->mobs == NULL)
        return (0);
    for (node_t *node = game->map->mobs; node->next != NULL;
    node = node->next) {
        rect = sfSprite_getGlobalBounds(((mob_t *)node->data)->animation->
        sprite);
        if (((mob_t *)node->data)->is_npc && sfFloatRect_intersects(&rect,
        &feet_rect, NULL)) {
            return (1);
        }
    }
    return (0);
}

int next_tile_has_collision(game_t *game)
{
    sfFloatRect feet_rect = get_feet_rect(game);
    tile_t *next_tile;
    tile_t *current_tile = get_tile_at_position(game, feet_rect);

    if (current_tile != NULL && current_tile->has_collision)
        return (0);
    feet_rect.left += game->hero->movement.x;
    feet_rect.top += game->hero->movement.y;
    next_tile = get_tile_at_position(game, feet_rect);
    if (next_tile == NULL)
        return (0);
    if (next_tile->has_collision)
        return (1);
    if (has_npc_collision(game))
        return (1);
    return (next_tile->has_collision == 1);
}

int get_next_level(game_t *game, int current_level)
{
    sfFloatRect feet_rect = get_feet_rect(game);

    if (game->hero->movement.x > 0 && current_level > 0)
        feet_rect.left += feet_rect.width;
    if (game->hero->movement.x < 0 && current_level > 0)
        feet_rect.left -= feet_rect.width;
    if (game->hero->movement.y < 0 && current_level > 0)
        feet_rect.top -= feet_rect.height;
    if (current_level == 0) {
        feet_rect.left += game->hero->movement.x;
        feet_rect.top += game->hero->movement.y;
    }
    return (get_level(game, feet_rect));
}

int get_current_level(game_t *game)
{
    sfFloatRect feet_rect = get_feet_rect(game);

    return (get_level(game, feet_rect));
}