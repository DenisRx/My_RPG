/*
** EPITECH PROJECT, 2021
** Library
** File description:
** my_str_start_with
*/

int my_str_start_with(const char *src, const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] != src[i])
            return (1);
    }
    return (0);
}