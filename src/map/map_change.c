/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** map_change
*/

#include "global.h"

void move_map_sprites(map_t *map, sfVector2f offset)
{
    layer_t *layer;
    tile_t *tile;

    for (node_t *node = map->layers; node != NULL; node = node->next) {
        layer = node->data;
        for (node_t *tile_node = layer->sprites; tile_node != NULL;
        tile_node = tile_node->next) {
            tile = tile_node->data;
            tile->sprite != NULL ? sfSprite_move(tile->sprite, offset)
        : (void)tile;
        }
    }
}

int get_next_map_index(game_t *game)
{
    hero_t *hero = game->hero;
    sfVector2f player_position = sfSprite_getPosition(hero->animation->sprite);

    if (player_position.y > game->map->height * game->map->tileheight * 2)
        return (0);
    if (player_position.y < 0)
        return (1);
    if (player_position.x < 0)
        return (2);
    if (player_position.x > game->map->width * game->map->tilewidth * 2)
        return (3);
    return (-1);
}

void change_map(__attribute__((unused))sfRenderWindow *window, game_t *game)
{
    int index = get_next_map_index(game);
    float multiply_x[] = {0, 0, 2, -2.f};
    float multiply_y[] = {-2.f, 2, 0, 0};
    int next_ids[] = {game->map->bot, game->map->top, game->map->left,
        game->map->right};
    direction_t directions[] = {BOT, TOP, LEFT, RIGHT};

    if (game->next_map != NULL || index == -1)
        return;
    game->next_map = get_map_from_id(game, next_ids[index]);
    game->map_offset = (sfVector2f){game->map->width * game->map->tilewidth *
        multiply_x[index], game->map->height *
        game->map->tileheight * multiply_y[index]};
    game->map_reset_offset = (sfVector2f){game->map_offset.x * -1,
        game->map_offset.y * -1};
    move_map_sprites(game->next_map, game->map_reset_offset);
    game->hero->movement = (sfVector2f){0, 0};
    game->hero->is_moving = 0;
    game->hero->knockback = (sfVector2f){0, 0};
    game->map_direction = directions[index];
    game->hero->bomb = NULL;
}

sfVector2f get_map_change_offset(game_t *game)
{
    sfVector2f offset = {0, 0};

    if (game->map_offset.x > 0)
        offset.x = 40;
    if (game->map_offset.x < 0)
        offset.x = -40;
    if (game->map_offset.y > 0)
        offset.y = 20;
    if (game->map_offset.y < 0)
        offset.y = -20;
    return (offset);
}

void animate_map_change(sfRenderWindow *window, game_t *game)
{
    sfVector2f offset = get_map_change_offset(game);

    show_map(window, game, game->next_map);
    if (sfClock_getElapsedTime(game->map_clock).microseconds /
    10000 >= 1) {
        move_map_sprites(game->map, offset);
        move_map_sprites(game->next_map, offset);
        move_maps_mobs(game->map, offset);
        move_objects(game->map->objects, offset);
        game->map_offset.x -= offset.x;
        game->map_offset.y -= offset.y;
        game->hero->position.x += offset.x;
        game->hero->position.y += offset.y;
        sfClock_restart(game->map_clock);
    }
    draw_animation(window, game->hero->animation, game);
}