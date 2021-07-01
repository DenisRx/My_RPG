/*
** EPITECH PROJECT, 2021
** myowl
** File description:
** audio
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "global.h"

sfSound *get_sound(char *filepath)
{
    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound,
    sfSoundBuffer_createFromFile(filepath));
    sfSound_setVolume(sound, 70);
    return (sound);
}

void change_audio(__attribute__((unused))sfRenderWindow *window,
char *new_value, game_t *game)
{
    sfMusic_setVolume(game->menu->menu_music, my_getnbr(new_value));
    sfMusic_setVolume(game->music_game, my_getnbr(new_value));
}