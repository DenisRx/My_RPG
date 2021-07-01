/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** text.c
*/

#include "global.h"

sfText *create_texts(const char *filepath, sfVector2f position, sfColor color)
{
    sfFont *font = sfFont_createFromFile(filepath);
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setPosition(text, position);
    return (text);
}

char *create_str(char *left_str, char *right)
{
    char *result = malloc(my_strlen(left_str) + my_strlen(right) + 1);
    int index = 0;

    for (int i = 0; left_str[i] != '\0'; i++) {
        result[index++] = left_str[i];
    }
    for (int i = 0; right[i] != '\0'; i++) {
        result[index++] = right[i];
    }
    result[index++] = '\0';
    return (result);
}