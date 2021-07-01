/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** get_flags
*/

#include <stdlib.h>
#include <stdarg.h>
#include "flags.h"
#include "my.h"

int check_zero_padding(char *flag_str)
{
    char *width = my_calloc(my_strlen(flag_str) + 1, '\0');
    int index = 0;
    int result;

    for (int i = 0; flag_str[i] != '\0'; i++) {
        if (flag_str[i] >= '0' && flag_str[i] <= '9')
            width[index++] = flag_str[i];
    }
    result = width[0] == '0';
    free(width);
    return (result);
}

int flag_contains(char *flag_str, char *flag)
{
    int x = 0;

    for (int i = 0; flag_str[i] != '\0'; i++) {
        for (x = 0; flag[x] != '\0' && flag[x] == flag_str[i]; x++) {
            if (x == my_strlen(flag) - 1)
                return (1);
            if (flag[x] == flag_str[i])
                i++;
        }
    }
    return (0);
}

int get_width(char *flag_str)
{
    char *width = my_calloc(my_strlen(flag_str) + 1, '\0');
    int index = 0;
    int result;

    for (int i = 0; flag_str[i] != '\0'; i++) {
        if (flag_str[i] >= '0' && flag_str[i] <= '9')
            width[index++] = flag_str[i];
    }
    result = my_getnbr(width);
    free(width);
    return (result);
}

struct flag_t get_flags(char *format, va_list arg_list)
{
    struct flag_t flag;
    char *flag_str = format;

    flag.alternate_form = flag_contains(flag_str, "#");
    flag.zero_padding = check_zero_padding(flag_str);
    flag.left_ajusted = flag_contains(flag_str, "-");
    flag.space = flag_contains(flag_str, " ");
    flag.sign = flag_contains(flag_str, "+");
    flag.width = get_width(flag_str);
    flag.char_flag = flag_contains(flag_str, "hh");
    flag.short_flag = flag_contains(flag_str, "h") && flag.char_flag != 1;
    flag.longlongint_flag = flag_contains(flag_str, "ll");
    flag.longint_flag = flag_contains(flag_str, "l")
    && flag.longlongint_flag != 1;
    if (flag_contains(flag_str, "*"))
        flag.width = va_arg(arg_list, int);
    return (flag);
}