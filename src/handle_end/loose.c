/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** end.c
*/

#include "global.h"

loose_t *init_loose(void)
{
    loose_t *info = malloc(sizeof(loose_t));

    info->background = load_sprite(BLACK_BG);
    info->lost = 0;
    info->title = create_texts(TITLE_FONT, (sfVector2f){540, 150}, sfWhite);
    sfSprite_setColor(info->background, sfColor_fromRGBA(255, 255, 255, 150));
    sfText_setString(info->title, "GAME OVER");
    sfText_setCharacterSize(info->title, 100);
    return (info);
}

void show_loose_menu(sfRenderWindow *window, game_t *game)
{
    struct menu *menu = game->loose;

    sfRenderWindow_drawSprite(window, game->loose_elems->background, NULL);
    sfRenderWindow_drawText(window, game->loose_elems->title, NULL);
    sfRenderWindow_drawSprite(window, menu->choice_bg, NULL);
    show_choices(window, menu);
    handle_hover(window, game, menu);
}

void reset_informations(game_t *game)
{
    map_t *map;

    game->map = get_map_from_id(game, 1);
    game->hero = create_hero(game);
    game->stats = init_stat_struct(game);
    game->paused = 0;
    game->save = 0;
    game->dialog = create_dialog();
    game->npc = generate_npc();
    game->map_clock = sfClock_create();
    game->inventory = init_inventory(game);
    game->life_infos = init_lives();
    game->quests = init_quests();
    for (node_t *node = game->maps; node != NULL; node = node->next) {
        map = node->data;
        map->mobs = generate_mobs(map->id, game);
        set_mobs_position(map);
    }
}

void go_to_menu_no_save(__attribute__((unused))sfRenderWindow* window,
game_t *game)
{

    game->next_state = START_MENU;
    sfMusic_stop(game->music_game);
    sfMusic_play(game->menu->menu_music);
    reset_informations(game);
}

void handle_loose_click(sfRenderWindow* win, sfEvent event, game_t *game)
{
    sfMouseButtonEvent mouse_event = event.mouseButton;
    struct menu *menu = game->loose;
    menu_choice_t *current = menu->choices->first;
    sfVector2i mouse_pos = (sfVector2i) {mouse_event.x, mouse_event.y};

    if (game->life_infos.remaining_lives != 0)
        return;
    while (current != NULL) {
        if (is_cursor_in_text(current->text, mouse_pos, game)) {
            sfSound_play(game->menu->select);
            sfText_setFillColor(current->text,
            sfColor_fromRGBA(53, 184, 33, 255));
            show_game(win, game);
            sfRenderWindow_display(win);
            sfSleep(sfMilliseconds(100));
            current->fptr(win, game);
            sfText_setFillColor(current->text, sfBlack);
        }
        current = current->next;
    }
}