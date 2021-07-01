/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** hud_texts
*/

#include "my.h"

char *get_text(const char *base, long number)
{
    char *text = malloc(my_strlen(base) + nb_size(number) + 1);
    char *nb = my_getstr(number);
    int index = 0;

    for (int i = 0; base[i] != '\0'; i++) {
        text[index++] = base[i];
    }
    for (int i = 0; nb[i] != '\0'; i++) {
        text[index++] = nb[i];
    }
    text[index++] = '\0';
    return (text);
}

char *get_score(long score)
{
    int size = nb_size((int)score);
    char *nb = my_getstr(score);
    char *text = malloc(size < 10 ? 12 : size + 1);
    int index = 0;

    for (int i = 0; i < 10 - size; i++) {
        text[index++] = '0';
    }
    for (int i = 0; nb[i] != '\0'; i++) {
        text[index++] = nb[i];
    }
    text[index++] = '\0';
    return (text);
}