/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** game
*/

#include <stdlib.h>
#include "global.h"

void setup_game_var(game_t *game)
{
    sfSprite_setPosition(game->background, (sfVector2f){ -100, 0 });
    sfSprite_setScale(game->background, (sfVector2f){1, 1.2});
    game->state = -1;
    game->res_ratio = 1;
    game->current_map = 1;
    game->stats = init_stat_struct(game);
    game->paused = 0;
    game->save = 0;
    game->dialog = create_dialog();
    game->npc = generate_npc();
    game->map_clock = sfClock_create();
    game->inventory = init_inventory(game);
    game->life_infos = init_lives();
    game->damage_anim = create_transition();
    game->damage_anim->fade_color = sfColor_fromRGBA(255, 0, 0, 110);
    game->quests = init_quests();
    game->loose = load_menu(game, choices_loose);
    game->loose_elems = init_loose();
    game->win = 0;
    game->win_clock = sfClock_create();
    game->engine = create_engine(settings_list[RAIN], 400);
}

game_t *load_game(int width, int height, sfRenderWindow *window)
{
    game_t *game = malloc(sizeof(game_t));

    game->window = window;
    game->cinematic = init_cinematic();
    game->resolution = (sfVector2u){width, height};
    game->background = create_background(START_MENU_BG);
    game->msg_box = create_message_box();
    game->maps = get_map_list("maps/mapping.xml", game);
    game->map = get_map_from_id(game, 1);
    game->next_map = NULL;
    game->menu = load_menu(game, choices_main);
    game->pause = load_menu(game, choices_pause);
    game->next_state = START_MENU;
    game->hero = create_hero(game);
    game->transition = create_transition();
    game->resolution = (sfVector2u) {BASE_WIDTH, BASE_HEIGHT};
    game->map_offset = (sfVector2f) {0, 0};
    game->music_game = sfMusic_createFromFile(game->map->music_path);
    setup_game_var(game);
    sfMusic_setVolume(game->music_game, 20);
    return (game);
}

void play_music(game_t *game)
{
    if (game->state == START_MENU) {
        if (sfMusic_getStatus(game->music_game) == sfPlaying)
            sfMusic_stop(game->music_game);
        if (sfMusic_getStatus(game->menu->menu_music) != sfPlaying) {
            sfMusic_play(game->menu->menu_music);
            sfMusic_setLoop(game->menu->menu_music, sfTrue);
        }
    }
    if (game->state == GAME) {
        sfMusic_stop(game->menu->menu_music);
        if (sfMusic_getStatus(game->music_game) != sfPlaying) {
            sfMusic_play(game->music_game);
            sfMusic_setLoop(game->music_game, sfTrue);
        }
    }
}

void change_state(sfRenderWindow *window, game_t *game)
{
    if (game->next_state != -1) {
        fade(window, game->transition, NULL);
        if (game->transition->done) {
            game->state = game->next_state;
            game->next_state = -1;
            game->transition->ascending = 0;
            game->transition->done = 0;
        }
    }
}

void check_victory(sfRenderWindow *window, game_t *game)
{
    if (game->win == 0)
        return;
    draw_bands(window);
    draw_win_msg(window);
    if (sfClock_getElapsedTime(game->win_clock).microseconds > 10000000)
        sfRenderWindow_close(window);
}