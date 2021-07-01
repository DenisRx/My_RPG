/*
** EPITECH PROJECT, 2020
** nb_size
** File description:
** Get size of a number
*/

#include "my.h"

int nb_size(int nb)
{
    int i = 0;

    if (nb == 0)
        return (1);
    nb = ABS(nb);
    while (nb > 0) {
        nb = nb / 10;
        i++;
    }
    return (i);
}