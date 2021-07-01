/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** Duplicate some string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_calloc(int size, char c);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *result = my_calloc(len + 1, '\0');

    for (int i = 0; i < len; i++) {
        result[i] = src[i];
    }
    return (result);
}
