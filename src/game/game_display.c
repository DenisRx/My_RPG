/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** game_display
*/

#include "global.h"

void display_game(sfRenderWindow* window, game_t *game)
{
    change_map(window, game);
    handle_map(window, game);
    handle_inventory(window, game);
    handle_stats(window, game);
    display_lives(window, game);
    show_dialog(window, game);
    handle_quest(window, game);
    show_damage(window, game->damage_anim, game);
    check_special_display(window, game);
}