/*
** EPITECH PROJECT, 2020
** concat_params
** File description:
** Concat some params
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src);

char *my_calloc(int size, char c);

char *concat_params(int argc, char **argv)
{
    int total_len = 0;
    char *result;

    for (int i = 0; i < argc; i++) {
        total_len = my_strlen(argv[i]);
    }
    result = my_calloc(total_len + argc, '\0');
    for (int i = 0; i < argc; i++) {
        if (my_strlen(argv[i]) > 0) {
            result = my_strcat(result, "\n");
            result = my_strcat(result, argv[i]);
        }
    }
    result = my_strcat(result, "\0");
    return (result);
}
