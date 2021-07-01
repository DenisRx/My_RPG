/*
** EPITECH PROJECT, 2020
** my_getstr
** File description:
** ok
*/

#include "my.h"

char get_char_nb(long *nb)
{
    int temp;

    if (*nb >= 0 && *nb < 10) {
        temp = *nb;
        *nb = 0;
        return (temp + 48);
    } else {
        temp = (*nb % 10);
        *nb = *nb / 10;
        return (temp + 48);
    }
}

char *my_getstr(long nb)
{
    char *str = my_calloc(nb_size(nb) + 1, '\0');
    int str_index = 0;

    if (nb == 0)
        return ("0");
    if (nb < 0) {
        str[str_index++] = '-';
        nb = nb * -1;
    }
    while (nb > 0) {
        str[str_index++] = get_char_nb(&nb);
    }
    str[str_index] = '\0';
    str = my_revstr(str);
    return (str);
}
