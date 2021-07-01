/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** load_save
*/

#include "global.h"
#include <SFML/Graphics.h>

void init_default_values(game_t *game)
{
    game->hero->position.x = 832;
    game->hero->position.y = 512;
    game->map = get_map_from_id(game, 1);
    game->hero->lives = 6;
    game->hero->damage = 30;
    game->hero->level = 1;
    game->hero->xp = 0;
    game->hero->critical_chance = 0;
    game->hero->resistance = 0;
    game->inventory->remaining = 24;
    game->hero->animation_list = create_animation_list(hero_animations,
    GREEN);
}

void load_save(__attribute__((unused))sfRenderWindow* window, game_t *game)
{
    game->next_state = GAME;
    game->transition->ascending = 1;
    game->save = 1;
    game->paused = 0;
    if (get_from_file(game) == 1)
        init_default_values(game);
}

void init_from_file(game_t *game, char **infos)
{
    game->hero->position.x = my_getnbr(infos[0]);
    game->hero->position.y = my_getnbr(infos[1]);
    game->hero->lives = my_getnbr(infos[3]);
    game->hero->damage = my_getnbr(infos[4]);
    game->hero->level = my_getnbr(infos[5]);
    game->hero->xp = my_getnbr(infos[6]);
    game->hero->critical_chance = my_getnbr(infos[7]);
    game->hero->resistance = my_getnbr(infos[8]);
    game->inventory->remaining = my_getnbr(infos[9]);
}

int get_from_file(game_t *game)
{
    char *file = load_file_in_mem(FILE_PATH);
    char **infos = NULL;
    node_t *node = game->inventory->boxes;

    if (!file)
        return (1);
    infos = my_str_to_word_array(file, "\n");
    init_from_file(game, infos);
    game->map = get_map_from_id(game, my_getnbr(infos[2]));
    game->hero->animation_list = create_animation_list(hero_animations,
    my_getnbr(infos[10]));
    for (int i = 11; infos[i] != NULL; i++) {
        ((box_t *)node->data)->empty = 1;
        ((box_t *)node->data)->element =
        create_object(my_getnbr(infos[i]), (sfVector2f){0, 0});
        node = node->next;
    }
    return (0);
}