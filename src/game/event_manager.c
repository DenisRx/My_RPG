/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** event_manager
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "global.h"

event_t EVENT_LIST[] = {
    {START_MENU, &handle_menu_click, sfEvtMouseButtonPressed},
    {OPTIONS_MENU, &handle_options_click, sfEvtMouseButtonPressed},
    {OPTIONS_MENU, &handle_options_hover, sfEvtMouseMoved},
    {HTP_MENU, &handle_htp_click, sfEvtMouseButtonPressed},
    {HTP_MENU, &handle_htp_hover, sfEvtMouseMoved},
    {GAME, &move_key_press, sfEvtKeyPressed},
    {GAME, &move_key_release, sfEvtKeyReleased},
    {GAME, &move_lost_focus, sfEvtLostFocus},
    {GAME, &attack_key_press, sfEvtKeyPressed},
    {GAME, &display_inventory, sfEvtKeyPressed},
    {GAME, &click_npc, sfEvtMouseButtonPressed},
    {GAME, &click_message, sfEvtMouseButtonPressed},
    {GAME, &click_inventory, sfEvtMouseButtonPressed},
    {GAME, &display_stats, sfEvtKeyPressed},
    {GAME, &handle_pause, sfEvtKeyPressed},
    {GAME, &handle_loose_click, sfEvtMouseButtonPressed},
    {GAME, &handle_pause_click, sfEvtMouseButtonPressed},
    {-1, NULL, -1}
};

void check_events(sfRenderWindow* window, sfEvent event, game_t *game)
{
    if (game->state == HTP_MENU) {
        sfSprite_setPosition(game->menu->back_arrow, (sfVector2f) {300, 150});
    } else
        sfSprite_setPosition(game->menu->back_arrow, (sfVector2f) {590, 390});
    for (int i = 0; EVENT_LIST[i].event != NULL; i++) {
        if (game->state == EVENT_LIST[i].state &&
            event.type == EVENT_LIST[i].type)
            EVENT_LIST[i].event(window, event, game);
    }
}

void handle_event(sfRenderWindow* window, sfEvent event, game_t *game)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        check_events(window, event, game);
    }
}

void handle_htp_hover(__attribute__((unused))sfRenderWindow* window,
sfEvent event, game_t *game)
{
    sfMouseMoveEvent mouse_event = event.mouseMove;
    sfVector2i mouse_pos = (sfVector2i) {mouse_event.x, mouse_event.y};
    struct menu *menu = game->menu;

    if (scale_on_hover(menu->options[0]->back_arrow, mouse_pos, game)) {
        play_sound(menu->options[0]->hover_left, game->menu->hover);
        menu->options[0]->hover_left = 1;
    } else {
        menu->options[0]->hover_left = 0;
    }
    if (scale_on_hover(menu->options[0]->next_arrow, mouse_pos, game)) {
        play_sound(menu->options[0]->hover_right, game->menu->hover);
        menu->options[0]->hover_right = 1;
    } else {
        menu->options[0]->hover_right = 0;
    }
    scale_on_hover(menu->back_arrow, mouse_pos, game);
}

void handle_htp_click(sfRenderWindow* window, sfEvent event,
game_t *game)
{
    sfMouseButtonEvent mouse_event = event.mouseButton;
    sfVector2i mouse_pos = (sfVector2i) {mouse_event.x, mouse_event.y};
    options_t *current_option;

    current_option = game->menu->options[0];
    options_click_left(window, mouse_event, game, current_option);
    options_click_right(window, mouse_event, game, current_option);
    if (is_cursor_in_sprite(game->menu->back_arrow, mouse_pos, game)) {
        game->state = START_MENU;
    }
}