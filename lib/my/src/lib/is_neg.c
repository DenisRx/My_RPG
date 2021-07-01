/*
** EPITECH PROJECT, 2020
** is_neg
** File description:
** ok
*/

int is_neg(char *nb)
{
    int i = 0;
    int neg = 1;

    while (nb[i] == '-') {
        neg = neg * -1;
        i++;
    }
    return neg;
}
