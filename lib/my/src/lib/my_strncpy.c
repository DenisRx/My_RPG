/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** Copy some string letter by letter
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    return dest;
}
