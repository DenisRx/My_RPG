/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** Calculate power
*/

#include <stdio.h>

long my_compute_power_rec(int nb, int p)
{
    long final = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    final *= my_compute_power_rec(nb, p-1);
    if ((nb > 0 && (final*nb < final)) ||
        (final < 0 && nb < 0 && (final*nb < final)) ||
        (final > 0 && nb < 0 && (final*nb > final)))
        return (0);
    return (final);
}
