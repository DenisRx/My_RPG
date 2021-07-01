/*
** EPITECH PROJECT, 2020
** flags_handle
** File description:
** flags_handle
*/

#include "my.h"
#include "flags.h"

void print_spaces(int len)
{
    for (int i = 0; i < len; i++) {
        my_putchar(' ');
    }
}

void print_zeros(int len)
{
    for (int i = 0; i < len; i++) {
        my_putchar('0');
    }
}

void print_sign(struct flag_t *flags, int arg)
{
    if (flags->sign || arg < 0) {
        my_putchar(arg < 0 ? '-': '+');
    }
}

int convert_type(struct flag_t *flags, int arg)
{
    if (flags->short_flag)
        arg = (int)(short int)arg;
    if (flags->char_flag)
        arg = (int)(char)(arg);
    return (arg);
}