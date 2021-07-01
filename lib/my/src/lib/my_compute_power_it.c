/*
** EPITECH PROJECT, 2020
** my_compute_power_it
** File description:
** Do power operation
*/

int my_compute_power_it(int nb, int p)
{
    int final = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    for (int i = 1; i < p; i++) {
        final *= nb;
        if ((nb > 0 && (final*nb < final)) ||
            (final < 0 && nb < 0 && (final*nb < final)) ||
            (final > 0 && nb < 0 && (final*nb > final)))
            return (0);
    }
    return (final);
}
