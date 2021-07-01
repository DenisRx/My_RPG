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

int print_string(char *format, va_list arg_list)
{
    char *arg = va_arg(arg_list, char *);
    struct flag_t flags = get_flags(format, arg_list);

    if (flags.left_ajusted == 0)
        print_spaces(flags.width - my_strlen(arg));
    my_putstr(arg, 1);
    if (flags.left_ajusted)
        print_spaces(flags.width - my_strlen(arg));
    return (MAX(flags.width, my_strlen(arg)));
}