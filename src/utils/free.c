/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** free
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "global.h"

void free_sound(sfSound *sound)
{
    sfSoundBuffer_destroy((sfSoundBuffer *)sfSound_getBuffer(sound));
    sfSound_destroy(sound);
}

void free_sprite(sfSprite *sprite)
{
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(sprite));
    sfSprite_destroy(sprite);
}

void free_2d_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}