/*
** EPITECH PROJECT, 2020
** Print String
** File description:
** print_string
*/

#include <stdio.h>
#include <stdarg.h>
#include "flags.h"
#include "my.h"
#include "protos.h"

int print_int(char *format, va_list arg_list)
{
    int arg = va_arg(arg_list, int);
    struct flag_t flags = get_flags(format, arg_list);

    arg = convert_type(&flags, arg);
    if (flags.sign || arg < 0)
        flags.width--;
    if (flags.space && flags.sign == 0 && arg > 0) {
        my_putchar(' ');
        flags.width--;
    }
    if (flags.left_ajusted == 0 && flags.zero_padding == 0)
        print_spaces(flags.width - nb_size(arg));
    print_sign(&flags, arg);
    if (flags.left_ajusted == 0 && flags.zero_padding)
        print_zeros(flags.width - nb_size(arg));
    my_put_nbr(ABS(arg));
    if (flags.left_ajusted)
        print_spaces(flags.width - nb_size(arg));
    return (MAX(flags.width, nb_size(arg)));
}

int print_octal(char *format, va_list arg_list)
{
    unsigned int arg = va_arg(arg_list, unsigned int);
    char *decimal = my_getstr(arg);
    char *octal = convert_base(decimal, "0123456789", "01234567");
    struct flag_t flags = get_flags(format, arg_list);

    arg = convert_type(&flags, arg);
    if (flags.alternate_form && arg != 0)
        flags.width--;
    if (flags.left_ajusted == 0 && flags.zero_padding == 0)
        print_spaces(flags.width - my_strlen(octal));
    if (flags.alternate_form && arg != 0)
        my_putstr("0", 1);
    if (flags.left_ajusted == 0 && flags.zero_padding)
        print_zeros(flags.width - my_strlen(octal));
    my_putstr(octal, 1);
    if (flags.left_ajusted)
        print_spaces(flags.width - my_strlen(octal));
    return (MAX(flags.width, nb_size(arg)));
}

int print_uint(char *format, va_list arg_list)
{
    unsigned int arg = va_arg(arg_list, unsigned int);
    char *decimal = my_getstr(arg);
    struct flag_t flags = get_flags(format, arg_list);


    if (flags.left_ajusted == 0 && flags.zero_padding == 0)
        print_spaces(flags.width - my_strlen(decimal));
    if (flags.left_ajusted == 0 && flags.zero_padding)
        print_zeros(flags.width - my_strlen(decimal));
    my_putstr(decimal, 1);
    if (flags.left_ajusted)
        print_spaces(flags.width - my_strlen(decimal));
    return (MAX(flags.width, my_strlen(decimal)));
}

int print_low_hex(char *format, va_list arg_list)
{
    unsigned int arg = va_arg(arg_list, unsigned int);
    char *decimal = my_getstr(arg);
    char *octal = convert_base(decimal, "0123456789", "0123456789abcdef");
    struct flag_t flags = get_flags(format, arg_list);

    arg = convert_type(&flags, arg);
    if (flags.alternate_form && arg != 0)
        flags.width -= 2;
    if (flags.left_ajusted == 0 && flags.zero_padding == 0)
        print_spaces(flags.width - my_strlen(octal));
    if (flags.alternate_form && arg != 0)
        my_putstr("0x", 1);
    if (flags.left_ajusted == 0 && flags.zero_padding)
        print_zeros(flags.width - my_strlen(octal));
    my_putstr(octal, 1);
    if (flags.left_ajusted)
        print_spaces(flags.width - my_strlen(octal));
    return (MAX(flags.width, nb_size(arg)));
}

int print_up_hex(char *format, va_list arg_list)
{
    unsigned int arg = va_arg(arg_list, unsigned int);
    char *decimal = my_getstr(arg);
    char *octal = convert_base(decimal, "0123456789", "0123456789ABCDEF");
    struct flag_t flags = get_flags(format, arg_list);

    arg = convert_type(&flags, arg);
    if (flags.alternate_form && arg != 0)
        flags.width -= 2;
    if (flags.left_ajusted == 0 && flags.zero_padding == 0)
        print_spaces(flags.width - my_strlen(octal));
    if (flags.alternate_form && arg != 0)
        my_putstr("0X", 1);
    if (flags.left_ajusted == 0 && flags.zero_padding)
        print_zeros(flags.width - my_strlen(octal));
    my_putstr(octal, 1);
    if (flags.left_ajusted)
        print_spaces(flags.width - my_strlen(octal));
    return (MAX(flags.width, nb_size(arg)));
}