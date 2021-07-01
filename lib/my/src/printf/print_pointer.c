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

int calculate_len(struct flag_t flags, char *str)
{
    int len = flags.width - my_strlen(str);
    int is_null = my_strcmp(str, "(nil)") == 0;
    if (is_null == 0)
        len = len - 2;
    if ((flags.sign || flags.space) && is_null == 0)
        len--;
    return (len);
}

char *get_pointer_base(char *decimal)
{
    if (my_strcmp(decimal, "0") == 0)
        return ("(nil)");
    return (convert_base(decimal, "0123456789", "0123456789abcdef"));
}

int print_pointer(char *format, va_list arg_list)
{
    void *arg = va_arg(arg_list, void *);
    char *decimal = my_getstr(ABS((long)arg));
    char *hexa = get_pointer_base(decimal);
    struct flag_t flags = get_flags(format, arg_list);
    int len = calculate_len(flags, hexa);

    if (flags.space && flags.sign == 0 && arg != 0)
        my_putchar(' ');
    if (flags.left_ajusted == 0 && (flags.zero_padding == 0 || arg == 0))
        print_spaces(len);
    if (arg != 0) {
        print_sign(&flags, 1);
        my_putstr("0x", 1);
    }
    if (flags.left_ajusted == 0 && flags.zero_padding && arg != 0)
        print_zeros(len);
    my_putstr(hexa, 1);
    if (flags.left_ajusted)
        print_spaces(len);
    return (MAX(flags.width, my_strlen(hexa) + 2));
}