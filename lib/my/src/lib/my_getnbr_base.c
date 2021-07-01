/*
** EPITECH PROJECT, 2020
** my_getnbr_base
** File description:
** Return decimal based on another base
*/

#include "my.h"

int my_get_indexof(char c, char const *base)
{
    int len = count_char(base);

    for (int i = 0; i < len; i++) {
        if (base[i] == c)
            return i;
    }
    return (0);
}

long my_getnbr_base(char const *str, char const *base)
{
    int base_len = count_char(base);
    int str_len = count_char(str);
    long nb = 0;
    int index = 0;
    int neg = 1;

    if (str[0] == '-')
        neg = -1;
    for (int i = 0; i < str_len; i++) {
        index = my_get_indexof(str[i], base);
        nb += index * my_compute_power_rec(base_len, str_len-i-1);
    }
    return nb * neg;
}