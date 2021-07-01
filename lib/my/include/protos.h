/*
** EPITECH PROJECT, 2020
** proto
** File description:
** protos
*/

#define MAX(x, y) (x > y ? x : y)

#ifndef PROTOS_H_
#define PROTOS_H_

#include "flags.h"
#include <stdio.h>
#include <stdarg.h>

int my_printf(char *, ...);
int not_handled(char *, va_list arg_list);
int print_string(char *, va_list arg_list);
int print_char(char *, va_list arg_list);
void print_spaces(int len);
void print_zeros(int len);
void print_sign(struct flag_t *flags, int arg);
int convert_type(struct flag_t *flags, int arg);
struct flag_t get_flags(char *format, va_list arg_list);

#endif /* !PROTOS_H_ */