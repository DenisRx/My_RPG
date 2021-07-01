/*
** EPITECH PROJECT, 2021
** my_owl
** File description:
** options
*/

#ifndef OPTIONS_H_
#define OPTIONS_H_

#include "global.h"

const char *options_list[] = {
    "RESOLUTION",
    "FPS",
    "MUSIC",
    "SOUND",
    "CHARACTER COLOR"
};

const char *resolution_list[] = {
    "1024x576",
    "1280x720",
    "1366x768",
    "1600x900",
    "1920x1080"
};

const char *fps_list[] = {
    "30",
    "60",
    "120",
    "144",
    "240"
};

const char *sound_list[] = {
    "0",
    "5",
    "10",
    "15",
    "20",
    "25",
    "30",
    "35",
    "40",
    "45",
    "50",
    "55",
    "60",
    "65",
    "70",
    "75",
    "80",
    "85",
    "90",
    "95",
    "100"
};

const char *char_list[] = {
    "GREEN",
    "BLUE",
    "PURPLE",
    "RED"
};

const char **options_choice_list[] = {
    resolution_list,
    fps_list,
    sound_list,
    sound_list,
    char_list
};

int default_options[] = {
    3,
    2,
    19,
    19,
    0
};

int max_options[] = {
    4,
    4,
    20,
    20,
    3
};

void change_resolution(sfRenderWindow *window, char *, game_t *game);
void change_fps(sfRenderWindow *window, char *new_value, game_t *game);
void change_audio(sfRenderWindow *window, char *new_value, game_t *game);
void change_character(sfRenderWindow *window, char *new_value, game_t *game);

void (*on_change_list[])(sfRenderWindow *, char *, game_t *) = {
    &change_resolution,
    &change_fps,
    &change_audio,
    &change_audio,
    &change_character
};

#endif /* !OPTIONS_H_ */
