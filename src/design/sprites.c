/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** sprites
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "global.h"

void check_file_path(const char *fpath)
{
    int fd = open(fpath, O_RDONLY);
    if (fd == -1) {
        my_printf("Error occured when loading sprites : %s\n", fpath);
    }
    close(fd);
}

sfSprite *load_sprite(const char *fpath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture;

    check_file_path(fpath);
    texture = sfTexture_createFromFile(fpath, NULL);
    sfSprite_setTexture(sprite, texture, 1);
    return (sprite);
}