/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** event_objects.c
*/

#include "protos.h"
#include "global.h"

void move_objects(node_t *first, sfVector2f offset)
{
    for (node_t *node = first; node != NULL; node = node->next) {
        sfSprite_move(((object_t *)node->data)->sprite, offset);
    }
}

void handle_objects(sfRenderWindow *win, node_t *first, game_t *game)
{
    for (node_t *node = first; node != NULL; node = node->next) {
        sfRenderWindow_drawSprite(win, ((object_t *)node->data)->sprite, NULL);
        if (check_collision_ground(game->hero->animation->sprite, node, game,
        win)) {
            handle_objects(win, game->map->objects, game);
            return;
        }
    }
}

int check_collision_ground(sfSprite *hero_sprite, node_t *node, game_t *game,
sfRenderWindow *window)
{
    sfFloatRect hero_field = sfSprite_getGlobalBounds(hero_sprite);
    sfFloatRect enemy_field = sfSprite_getGlobalBounds(((object_t *)node->data)
    ->sprite);

    if (sfFloatRect_intersects(&hero_field, &enemy_field, NULL)) {
        if (game->inventory->remaining > 0) {
            game->inventory->remaining -= 1;
            store_in_inventory(((object_t *)node->data), game);
            game->map->objects = remove_of_ground_list(game, node);
            return (1);
        } else
            handle_full_inventory(window, game);
    }
    return (0);
}