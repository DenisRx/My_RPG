/*
** EPITECH PROJECT, 2020
** Print Double
** File description:
** print_double
*/

#include "my.h"
#include "flags.h"
#include "protos.h"
#include <stdio.h>
#include <stdarg.h>

int get_nb(double nb, char *str)
{
    int count = 0;
    int index = 0;

    while (nb < 10000000) {
        count--;
        nb = nb * 10;
    }
    while (nb > 10000000) {
        count++;
        nb = nb / 10;
    }
    for (; nb > 10; nb = nb / 10) {
        count++;
        str[index++] = (int)nb % 10 + 48;
    }
    str[index++] = '.';
    str[index] = (int)nb % 10 + 48;
    return (count + 1);
}

int print_double(char *format, va_list arg_list)
{
    double arg = va_arg(arg_list, double);
    char *str = my_calloc(13, '\0');
    int count = get_nb(arg, str);
    struct flag_t flags = get_flags(format, arg_list);

    if (flags.left_ajusted == 0)
        print_spaces(flags.width - 13);
    my_putstr(my_revstr(str), 1);
    my_putstr("e+", 1);
    if (count > 10)
        my_put_nbr(count-1);
    else {
        my_putchar('0');
        my_putchar(count - 1 + 48);
    }
    if (flags.left_ajusted)
        print_spaces(flags.width - 13);
    return (13);
}

int print_double_up(char *format, va_list arg_list)
{
    double arg = va_arg(arg_list, double);
    char *str = my_calloc(13, '\0');
    int count = get_nb(arg, str);
    struct flag_t flags = get_flags(format, arg_list);

    if (flags.left_ajusted == 0)
        print_spaces(flags.width - 13);
    my_putstr(my_revstr(str), 1);
    my_putstr("E+", 1);
    if (count > 10)
        my_put_nbr(count-1);
    else {
        my_putchar('0');
        my_putchar(count - 1 + 48);
    }
    if (flags.left_ajusted)
        print_spaces(flags.width - 13);
    return (13);
}
