/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** background
*/

#include <SFML/Graphics.h>
#include "global.h"

sfTexture *load_background(char *fpath)
{
    return (sfTexture_createFromFile(fpath, NULL));
}

sfSprite *create_background(char *fpath)
{
    sfSprite *background = sfSprite_create();
    sfSprite_setTexture(background, load_background(fpath), 1);
    return (background);
}

void show_background(sfRenderWindow* window, sfSprite *backgroundSprite)
{
    sfRenderWindow_drawSprite(window, backgroundSprite, NULL);
}