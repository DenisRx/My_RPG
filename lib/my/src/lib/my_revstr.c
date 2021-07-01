/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** Reverse some string
*/

#include <stdio.h>

int count_char(char *str);

char *my_revstr(char *str)
{
    char tmp;
    int len = count_char(str)-1;

    for (int i = 0; i < len; i++) {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        len--;
    }
    return (str);
}
