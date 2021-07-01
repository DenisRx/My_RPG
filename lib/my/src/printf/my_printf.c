/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include "protos.h"
#include "specifiers.h"

int call_fn_specifier(char *format_string, va_list arg_list)
{
    for (int i = 0; SPECIFIER_LIST[i].c != '\0'; i++) {
        if (SPECIFIER_LIST[i].c == format_string[my_strlen(format_string) - 1])
            return SPECIFIER_LIST[i].fptr(format_string, arg_list);
    }
    return (0);
}

int is_specifier(char c)
{
    for (int i = 0; SPECIFIER_LIST[i].c != '\0'; i++) {
        if (SPECIFIER_LIST[i].c == c)
            return (1);
    }
    return (0);
}

char *get_format_string(char *format)
{
    char *format_string = my_calloc(my_strlen(format) + 2, '\0');

    for (int i = 0; format[i] != '\0'; i++) {
        format_string[i] = format[i];
        if (i > 0 && is_specifier(format[i])){
            format_string[i + 1] = 0;
            return (format_string);
        }
    }
    return ("");
}

int my_printf(char *format, ...)
{
    va_list arg_list;
    int printed_char = 0;
    char *format_string;

    va_start(arg_list, format);
    for (int i = 0; format[i] != '\0'; i = 0) {
        if (format[i] == '%') {
            format_string = get_format_string(format);
            printed_char += call_fn_specifier(format_string, arg_list);
            format = format + my_strlen(format_string);
            free(format_string);
        } else {
            my_putchar(format[i]);
            format = format + 1;
            printed_char++;
        }
    }
    va_end(arg_list);
    return (printed_char);
}