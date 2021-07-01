/*
** EPITECH PROJECT, 2020
** specifier
** File description:
** specifiers
*/

#ifndef SPECIFIERS_H_
#define SPECIFIERS_H_

#include <stdio.h>
#include <stdarg.h>

int not_handled(char *, va_list);
int print_string(char *, va_list);
int print_char(char *, va_list);
int print_int(char *, va_list);
int print_octal(char *, va_list);
int print_uint(char *, va_list);
int print_low_hex(char *, va_list);
int print_up_hex(char *, va_list);
int print_double(char *, va_list);
int print_double_up(char *, va_list);
int print_pointer(char *, va_list);
int print_binary(char *, va_list);
int print_string_custom(char *, va_list);
int print_percent(char *, va_list);

struct specifiers_t
{
    char c;
    int (*fptr)(char *, va_list arg_list);
};

const struct specifiers_t SPECIFIER_LIST[] =
{
    {'d', &print_int},
    {'i', &print_int},
    {'o', &print_octal},
    {'u', &print_uint},
    {'x', &print_low_hex},
    {'X', &print_up_hex},
    {'e', &print_double},
    {'E', &print_double_up},
    {'f', &not_handled},
    {'F', &not_handled},
    {'g', &not_handled},
    {'G', &not_handled},
    {'a', &not_handled},
    {'A', &not_handled},
    {'c', &print_char},
    {'s', &print_string},
    {'p', &print_pointer},
    {'n', &not_handled},
    {'m', &not_handled},
    {'%', &print_percent},
    {'b', &print_binary},
    {'S', &print_string_custom},
    {'\0', &not_handled}
};

#endif /* !SPECIFIERS_H_ */
