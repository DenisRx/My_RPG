/*
** EPITECH PROJECT, 2020
** convert_base
** File description:
** Convert base to another
*/

#include <stdlib.h>
#include "my.h"

int my_strbase_tobase(char *result, long nbr, char const *base_to, int index)
{
    int base_len = my_strlen(base_to);
    int nb;

    nb = nbr % base_len;
    nbr = nbr / base_len;
    if (nbr > 0)
        my_strbase_tobase(result, nbr, base_to, index - 1);
    result[index] = base_to[nb];
    return (0);
}

char *return_zero(char const *base_to)
{
    char *result = malloc(2);

    result[0] = base_to[0];
    result[1] = '\0';
    return (result);
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    long dec = my_getnbr_base(nbr, base_from);
    int base_len = my_strlen(base_to);
    char *result;
    int count = 0;
    long nb = dec;

    if (dec == 0)
        return (return_zero(base_to));
    while (nb > 0) {
        nb = nb / base_len;
        count++;
    }
    result = my_calloc(count + 1, '\0');
    if (dec < 0){
        dec = -dec;
        result[0] = '-';
    }
    my_strbase_tobase(result, dec, base_to, count - 1);
    return (result);
}
