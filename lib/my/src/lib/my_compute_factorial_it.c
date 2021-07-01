/*
** EPITECH PROJECT, 2020
** my_compute_factorial_it
** File description:
** Calculate Factorial
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb == 0)
        return (1);
    if (nb < 0 || nb > 12)
        return (0);
    for (int i = nb; i > 0; i--) {
        result = result * i;
    }
    if (result < 0)
        return (0);
    return result;
}
