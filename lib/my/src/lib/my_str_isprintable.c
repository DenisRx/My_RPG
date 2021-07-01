/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** Check if string is printable
*/

int my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 6 || (str[i] >= 16 && str[i] <= 31) || str[i] > 126)
            return (0);
    }
    return (1);
}
