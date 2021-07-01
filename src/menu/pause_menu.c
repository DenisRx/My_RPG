/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** pause_menu.c
*/

#include "global.h"

void handle_pause(__attribute__((unused))sfRenderWindow *window,
sfEvent event, game_t *game)
{
    if (event.key.code == sfKeyEscape)
        game->paused = !game->paused;
}

void show_pause_menu(sfRenderWindow *window, game_t *game)
{
    struct menu *menu = game->pause;

    sfRenderWindow_drawSprite(window, menu->choice_bg, NULL);
    show_choices(window, menu);
    handle_hover(window, game, menu);
}

void handle_pause_click(sfRenderWindow* window, sfEvent event,
game_t *game)
{
    sfMouseButtonEvent mouse_event = event.mouseButton;
    struct menu *menu = game->pause;
    menu_choice_t *current = menu->choices->first;
    sfVector2i mouse_pos = (sfVector2i) {mouse_event.x, mouse_event.y};

    if (!game->paused)
        return;
    while (current != NULL) {
        if (is_cursor_in_text(current->text, mouse_pos, game)) {
            sfSound_play(game->menu->select);
            sfText_setFillColor(current->text,
            sfColor_fromRGBA(53, 184, 33, 255));
            show_game(window, game);
            sfRenderWindow_display(window);
            sfSleep(sfMilliseconds(100));
            current->fptr(window, game);
            sfText_setFillColor(current->text, sfBlack);
        }
        current = current->next;
    }
}