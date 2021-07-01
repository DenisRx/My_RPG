/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** map_manager
*/

#include <SFML/Graphics.h>
#include "global.h"

void show_layer(sfRenderWindow *window, layer_t *layer, game_t *game)
{
    node_t *node = layer->sprites;
    tile_t *data;

    while (node != NULL) {
        data = node->data;
        if (my_strcmp(layer->name, "Objects") == 0) {
            handle_mobs(window, game, data);
            handle_hero(window, game, data);
            handle_objects(window, game->map->objects, game);
        }
        if (data->sprite != NULL) {
            sfRenderWindow_drawSprite(window, data->sprite, NULL);
        }
        node = node->next;
    }
}

void show_map(sfRenderWindow *window, game_t *game, map_t *map)
{
    layer_t *data = NULL;

    for (node_t *node = map->layers; node != NULL; node = node->next) {
        data = node->data;
        if (data->visible)
            show_layer(window, data, game);
    }
    if (get_property_int(map->tag, "boss_map", 0) && game->next_map == NULL)
        handle_cinematic(window, game->cinematic, game);
    if (map->id == 28)
        check_quests(game);
    if (get_property_int(map->tag, "env", -1) != -1 && game->next_map == NULL) {
        draw_particles(window, game->engine);
    }
}

void reset_map(game_t *game)
{
    if (game->map->music_id != game->next_map->music_id) {
        sfMusic_stop(game->music_game);
        game->music_game = sfMusic_createFromFile(game->next_map->music_path);
        sfMusic_setVolume(game->music_game, 20);
    }
    if (get_property_int(game->map->tag, "env", -1) !=
    get_property_int(game->next_map->tag, "env", -1) &&
    get_property_int(game->next_map->tag, "env", -1) != -1) {
        update_particule_engine(game->engine,
        settings_list[get_property_int(game->next_map->tag, "env", -1)]);
    }
    move_map_sprites(game->map, game->map_reset_offset);
    move_maps_mobs(game->map, game->map_reset_offset);
    move_objects(game->map->objects, game->map_reset_offset);
    game->map = game->next_map;
    game->next_map = NULL;
}

void handle_map_reset(game_t *game)
{
    reset_map(game);
    if (game->map_direction == TOP)
        game->hero->position.y = game->resolution.y - 1;
    if (game->map_direction == BOT)
        game->hero->position.y = 1;
    if (game->map_direction == LEFT)
        game->hero->position.x = game->resolution.x - 1;
    if (game->map_direction == RIGHT)
        game->hero->position.x = 1;
    sfSprite_setPosition(game->hero->animation->sprite,
    game->hero->position);
    game->cinematic->played = 0;
}

void handle_map(sfRenderWindow *window, game_t *game)
{
    show_map(window, game, game->map);
    if (game->map_offset.x != 0 || game->map_offset.y != 0)
        animate_map_change(window, game);
    if (game->map_offset.x == 0 && game->map_offset.y == 0 &&
    game->next_map != NULL) {
        handle_map_reset(game);
    }
}