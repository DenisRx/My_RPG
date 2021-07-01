/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** game_manager
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "global.h"

void set_text_property(sfText *text, sfVector2f position, int font_size,
sfColor color)
{
    sfText_setPosition(text, position);
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, font_size);
}

void set_center_position(sfText *text, int offset_y, game_t *game)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);

    sfText_setOrigin(text, (sfVector2f){rect.width/2, rect.height/2});
    sfText_setPosition(text, (sfVector2f){game->resolution.x/2,
        game->resolution.y/2 + offset_y});
}

void start_game(__attribute__((unused))sfRenderWindow* window, game_t *game)
{
    game->next_state = GAME;
    game->transition->ascending = 1;
    sfMusic_play(game->music_game);
}

void check_special_display(sfRenderWindow* window, game_t *game)
{
    if (game->paused)
        show_pause_menu(window, game);
    if (game->life_infos.remaining_lives <= 0) {
        game->hero->animation =
        get_animation_w_name(game->hero->animation_list, "dies");
        sfSprite_setPosition(game->hero->animation->sprite,
        game->hero->position);
        if (is_animation_ended(game->hero->animation) == 0 &&
            game->loose_elems->lost == 0)
            handle_animation(window, game->hero->animation);
        else if (game->loose_elems->lost == 0) {
            game->loose_elems->lost = 1;
            sfMusic_stop(game->music_game);
            game->music_game = sfMusic_createFromFile("assets/sounds/dead.ogg");
            sfMusic_setVolume(game->music_game, 20);
            sfMusic_play(game->music_game);
        }
        if (game->loose_elems->lost == 1)
            show_loose_menu(window, game);
    }
}

void show_game(sfRenderWindow* window, game_t *game)
{
    play_music(game);
    sfRenderWindow_drawSprite(window, game->background, NULL);
    if (game->state == START_MENU)
        show_menu(window, game);
    if (game->state == OPTIONS_MENU)
        show_options(window, game);
    if (game->state == HTP_MENU)
        show_how_to_play(window, game);
    change_state(window, game);
    if (game->state == GAME) {
        display_game(window, game);
        check_victory(window, game);
    }
}