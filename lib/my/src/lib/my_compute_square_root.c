/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** Calculate power root
*/

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb)
{
    if (nb == 1)
        return (1);
    if (nb < 1)
        return (0);
    for (int i = 1; i <= nb/2; i++) {
        if (i * i == nb)
            return (i);
        if (i * i > nb || i * i < 0)
            return (0);
    }
    return (0);
}
