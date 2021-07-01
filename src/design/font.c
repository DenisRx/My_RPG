/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** font
*/

#include <SFML/Graphics.h>
#include "global.h"

void print_text(sfRenderWindow* window, struct text_sprite text_infos,
sfFont *font, sfText *text)
{
    sfText_setFont(text, font);
    sfText_setString(text, text_infos.message);
    sfText_setCharacterSize(text, text_infos.size);
    sfText_setColor(text, text_infos.color);
    sfText_setPosition(text, text_infos.position);
    sfRenderWindow_drawText(window, text, NULL);
}

sfText *create_text(sfFont *font, int size)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfBlack);
    return (text);
}