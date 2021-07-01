/*
** EPITECH PROJECT, 2020
** my_putnbr_base
** File description:
** Convert decimal to given base
*/

#include <stdio.h>
#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int base_len = count_char(base);
    int nb;

    if (nbr == -2147483648)
        return (nbr);
    if (base[0] == '\0')
        return (-1);
    if (nbr < 0){
        nbr = -nbr;
        my_putchar('-');
    }
    nb = nbr % base_len;
    nbr = nbr / base_len;
    if (nbr > 0)
        my_putnbr_base(nbr, base);
    my_putchar(base[nb]);
    return (0);
}