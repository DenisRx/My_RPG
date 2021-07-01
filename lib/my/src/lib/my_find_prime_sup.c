/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** Find superior prime
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (; nb <= 2147483647; nb++) {
        if (my_is_prime(nb) == 1)
            return nb;
    }
    return (0);
}
