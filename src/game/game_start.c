/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** game_start
*/

#include "global.h"

void show_loading_screen(sfRenderWindow *window)
{
    sfText *loading = sfText_create();
    sfFont *font = sfFont_createFromFile(TITLE_FONT);
    sfFloatRect rect;

    sfRenderWindow_clear(window, sfBlack);
    sfText_setFont(loading, font);
    sfText_setString(loading, "Loading...");
    sfText_setCharacterSize(loading, 60);
    rect = sfText_getGlobalBounds(loading);
    sfText_setOrigin(loading, (sfVector2f){rect.width/2, rect.height/2});
    sfText_setPosition(loading, (sfVector2f){BASE_WIDTH/2, BASE_HEIGHT/2});
    sfRenderWindow_drawText(window, loading, NULL);
    sfRenderWindow_display(window);
}

void show_help_message(void)
{
    char *help_message = load_file_in_mem("description");
    write(1, help_message, my_strlen(help_message));
}