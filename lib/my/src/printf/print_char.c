/*
** EPITECH PROJECT, 2020
** Print String
** File description:
** print_string
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include "protos.h"
#include "flags.h"

int print_char(char *format, va_list arg_list)
{
    char arg = va_arg(arg_list, int);
    struct flag_t flags = get_flags(format, arg_list);

    for (int i = 0; i < flags.width - 1 && flags.left_ajusted == 0; i++) {
        my_putchar(' ');
    }
    my_putchar(arg);
    for (int i = 0; i < flags.width - 1 && flags.left_ajusted; i++) {
        my_putchar(' ');
    }
    return (1);
}

int print_percent(void)
{
    my_putchar('%');
    return (1);
}