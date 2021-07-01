/*
** EPITECH PROJECT, 2020
** my_evil_str
** File description:
** Reverse string
*/

#include <stdio.h>

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int len = my_strlen(str) - 1;
    int count = 0;
    char tmp;

    for (int i = len; i > count; i--) {
        tmp = str[count];
        str[count] = str[i];
        str[i] = tmp;
        count++;
    }
    return (str);
}
