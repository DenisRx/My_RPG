/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** display_menu.c
*/

#include "global.h"

void check_stats(game_t *game)
{
    if (game->stats->displayed == 0 && game->inventory->displayed == 0) {
        game->stats->displayed = 1;
    } else
        game->stats->displayed = 0;
}

void print_stats(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawText(window, game->stats->title, NULL);
    sfRenderWindow_drawText(window, game->stats->level_txt, NULL);
    sfRenderWindow_drawText(window, game->stats->xp_txt, NULL);
    sfRenderWindow_drawText(window, game->stats->lives_txt, NULL);
    sfRenderWindow_drawText(window, game->stats->damage_txt, NULL);
    sfRenderWindow_drawText(window, game->stats->crit_txt, NULL);
    sfRenderWindow_drawText(window, game->stats->res_txt, NULL);
}

void handle_stats(sfRenderWindow *window, game_t *game)
{
    if (game->stats->displayed == 1) {
        sfRenderWindow_drawSprite(window, game->stats->bg, NULL);
        set_stats_infos(game->stats, game);
        print_stats(window, game);
    }
}

void display_stats(__attribute__((unused))sfRenderWindow *window, sfEvent event,
game_t *game)
{
    if (event.key.code == sfKeyS) {
        check_stats(game);
        game->hero->movement = (sfVector2f){0, 0};
        game->hero->is_moving = 0;
    }
}