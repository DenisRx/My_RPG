/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** update_level.c
*/

#include "global.h"

void check_res_increase(game_t *game)
{
    if ((game->hero->resistance / 2) % 2 == 0
    || (game->hero->resistance == 10)) {
        game->hero->lives += 2;
        (&game->life_infos)->max_lives += 2;
    }
}

void check_level(game_t *game)
{
    int expected_xp = 30 * game->hero->level;
    inv_msg_t *inv = game->inventory->inv_msg;

    if (game->hero->xp >= expected_xp) {
        game->hero->xp -= expected_xp;
        game->hero->level += 1;
        game->hero->resistance += 5;
        game->hero->damage += 5;
        game->hero->resistance += 5;
        check_res_increase(game);
        (&game->life_infos)->remaining_lives = (&game->life_infos)->max_lives;
        game->hero->critical_chance += 5;
        display_dialog(game, inv->msg_bg, inv->level_up, 2000000);
    }
}