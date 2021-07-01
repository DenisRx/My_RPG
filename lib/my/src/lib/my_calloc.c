/*
** EPITECH PROJECT, 2020
** my_calloc
** File description:
** Some custom calloc
*/

#include <stdlib.h>

void *malloc(size_t size);

char *my_calloc(int size, char c)
{
    char *result = malloc(size);

    if (result == 0)
        return (NULL);
    for (int i = 0; i < size; i++) {
        result[i] = c;
    }
    return (result);
}
