/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Get nbr from string
*/

#include <stdio.h>

int my_strlen(char const *str);

int my_power(int a, int b)
{
    int final = a;

    if (b == 0)
        return 1;
    for (int i = 1; i < b; i++) {
        final *= a;
    }
    return final;
}

int calculate_nb(int count, int nb[10], int neg)
{
    int final_nb = 0;

    for (int i = 0; i < count; i++) {
        if (neg < 0)
            final_nb += -nb[i] * my_power(10, count-i-1);
        else
            final_nb += nb[i] * my_power(10, count-i-1);
        if ((final_nb > 0 && neg < 0) ||
            (final_nb < 0 && neg > 0))
            return (0);
    }
    return (final_nb);
}

int my_getnbr(char const *str)
{
    char c = 0;
    int len = my_strlen(str);
    int nb[10];
    int nb_count = 0;
    int neg = 1;

    for (int i = 0; i < len; i++)
        if (str[i] == '-')
            neg = -neg;
    for (int i = 0; i < len; i++) {
        c = str[i];
        if (c >= 48 && c <= 57) {
            nb[nb_count] = c - 48;
            nb_count++;
        } else if (nb_count > 0) {
            break;
        }
    }
    if (nb_count > 10)
        return (0);
    return (calculate_nb(nb_count, nb, neg));
}
