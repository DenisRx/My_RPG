/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** Put every letter in uppercase
*/

#include <stdio.h>

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return str;
}
