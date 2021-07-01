/*
** EPITECH PROJECT, 2020
** Print pointer
** File description:
** print_pointer
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include "protos.h"
#include "flags.h"

int print_binary(char *format, va_list arg_list)
{
    unsigned int arg = va_arg(arg_list, unsigned int);
    char *decimal = my_getstr(arg);
    char *octal = convert_base(decimal, "0123456789", "01");
    struct flag_t flags = get_flags(format, arg_list);

    arg = convert_type(&flags, arg);
    if (flags.alternate_form)
        flags.width -= 2;
    if (flags.left_ajusted == 0 && flags.zero_padding == 0)
        print_spaces(flags.width - my_strlen(octal));
    if (flags.alternate_form)
        my_putstr("0b", 1);
    if (flags.left_ajusted == 0 && flags.zero_padding)
        print_zeros(flags.width - my_strlen(octal));
    my_putstr(octal, 1);
    if (flags.left_ajusted)
        print_spaces(flags.width - my_strlen(octal));
    return (my_strlen(octal));
}

void print_zero_before(char c)
{
    if (c < 10) {
        my_putchar('0');
        my_putchar('0');
    } else if (c < 100) {
        my_putchar('0');
    }
}

int print_unprintable(char c)
{
    char *octal;

    my_putchar('\\');
    print_zero_before(c);
    octal = convert_base(my_getstr(c), "0123456789", "01234567");
    my_putstr(octal, 1);
    return (4);
}

int print_string_custom(char *format, va_list arg_list)
{
    int printed_char = 0;
    char *arg = va_arg(arg_list, char *);
    struct flag_t flags = get_flags(format, arg_list);

    if (flags.left_ajusted == 0)
        print_spaces(flags.width - my_strlen(arg));
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] < 32 || arg[i] >= 127) {
            printed_char += print_unprintable(arg[i]);
        } else {
            printed_char++;
            my_putchar(arg[i]);
        }
    }
    if (flags.left_ajusted)
        print_spaces(flags.width - printed_char);
    return (printed_char);
}