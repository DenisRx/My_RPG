/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** Capitalize every word
*/

#include <stdio.h>

int is_up_letter(char c);

int is_low_letter(char c);

int is_number(char c);

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_low_letter(str[i]) == 1 &&
            ((str[i-1] >= 32 && str[i-1] <= 47) || i-1 < 0))
            str[i] = str[i] - 32;
        else if (is_up_letter(str[i]) == 1 &&
            (is_low_letter(str[i-1]) || is_number(str[i-1])))
            str[i] = str[i] + 32;
    }
    return str;
}
