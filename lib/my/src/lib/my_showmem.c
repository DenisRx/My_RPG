/*
** EPITECH PROJECT, 2020
** my_showmem
** File description:
** Show mem
*/

#include "my.h"

int my_showmem(char const *str, int size)
{
    my_putstr(str, 1);
    my_put_nbr(size);
    return (0);
}
