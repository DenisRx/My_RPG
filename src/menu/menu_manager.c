/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** menu_manager
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "menu.h"
#include "text.h"
#include "protos.h"
#include "state.h"

void resume_game(__attribute__((unused))sfRenderWindow* window, game_t *game)
{
    game->paused = 0;
}

void show_choices(sfRenderWindow *window, struct menu *menu)
{
    menu_choice_t *current = menu->choices->first;

    while (current != NULL) {
        sfRenderWindow_drawText(window, current->text, NULL);
        current = current->next;
    }
}

void show_menu(sfRenderWindow *window, game_t *game)
{
    struct menu *menu = game->menu;

    sfRenderWindow_drawSprite(window, menu->choice_bg, NULL);
    sfRenderWindow_drawSprite(window, menu->logo, NULL);
    show_choices(window, menu);
    handle_hover(window, game, game->menu);
}

void show_options(sfRenderWindow *window, game_t *game)
{
    struct menu *menu = game->menu;

    sfRenderWindow_drawSprite(window, menu->choice_bg, NULL);
    sfRenderWindow_drawSprite(window, menu->logo, NULL);
    handle_hover(window, game, game->menu);
    for (int i = 0; i < 5; i++) {
        sfRenderWindow_drawText(window, menu->options[i]->title_text, NULL);
        sfRenderWindow_drawText(window, menu->options[i]->choice_text, NULL);
        sfRenderWindow_drawSprite(window, menu->options[i]->back_arrow, NULL);
        sfRenderWindow_drawSprite(window, menu->options[i]->next_arrow, NULL);
    }
    sfRenderWindow_drawSprite(window, menu->back_arrow, NULL);
}

void show_how_to_play(sfRenderWindow *window, game_t *game)
{
    struct menu *menu = game->menu;
    sfVector2f vector = {200, -500};

    sfSprite_setPosition(menu->how_to_play, vector);
    handle_hover(window, game, game->menu);
    sfRenderWindow_drawSprite(window, menu->how_to_play, NULL);
    sfRenderWindow_drawSprite(window, menu->back_arrow, NULL);
}