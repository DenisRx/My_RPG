/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Find first occurence of a string
*/

#include <stdio.h>

int count_char(char *str);

char *my_strstr(char *str, char *to_find)
{
    if (str[0] == 0)
        return (0);
    for (int i = 0; to_find[i] != '\0'; i++) {
        if (to_find[i] != str[i])
            return (my_strstr(str + 1, to_find));
    }
    return (str);
}
