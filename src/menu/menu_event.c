/*
** EPITECH PROJECT, 2021
** myowl
** File description:
** menu_event
*/

#include "global.h"

void exit_game(sfRenderWindow* window, __attribute__((unused))game_t *game)
{
    sfRenderWindow_close(window);
}

void exit_save(sfRenderWindow* window, game_t *game)
{
    write_in_file(game);
    sfRenderWindow_close(window);
}

void go_to_options(__attribute__((unused))sfRenderWindow* window, game_t *game)
{
    game->state = OPTIONS_MENU;
}

void go_to_main_menu(__attribute__((unused))sfRenderWindow* window,
game_t *game)
{
    write_in_file(game);
    game->next_state = START_MENU;
}

void go_to_how_to_play(__attribute__((unused))sfRenderWindow* window,
game_t *game)
{
    game->state = HTP_MENU;
}