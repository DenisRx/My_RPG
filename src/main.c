/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** main.c
*/


#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"
#include "my.h"

void game_loop(sfRenderWindow* window)
{
    game_t *game = load_game(BASE_WIDTH, BASE_HEIGHT, window);
    sfEvent event;

    sfMusic_setVolume(game->menu->menu_music, 10);
    sfMusic_play(game->menu->menu_music);
    while (sfRenderWindow_isOpen(window)) {
        handle_event(window, event, game);
        sfRenderWindow_clear(window, sfBlack);
        show_game(window, game);
        sfRenderWindow_display(window);
    }
}

int check_env_display(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_str_start_with(env[i], "DISPLAY") == 0)
            return (EXIT_SUCCESS);
    }
    return (EXIT_FAIL);
}

int gamestart(void)
{
    sfVideoMode mode = {BASE_WIDTH, BASE_HEIGHT, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "RPG", sfClose, NULL);
    if (!window)
        return (EXIT_FAIL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setKeyRepeatEnabled(window, 0);
    srand(random_val());
    show_loading_screen(window);
    game_loop(window);
    sfRenderWindow_destroy(window);
    return (EXIT_SUCCESS);
}

int main(int argc, char **argv, char **env)
{
    if (argc > 1 && my_strcmp(argv[1], "-h") == 0) {
        show_help_message();
        return (EXIT_SUCCESS);
    }
    if (check_env_display(env) == EXIT_FAIL)
        return (EXIT_FAIL);
    return (gamestart());
}