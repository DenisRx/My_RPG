/*
** EPITECH PROJECT, 2020
** utils
** File description:
** Functions used everywhere
*/

int count_char(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}

int is_up_letter(char c)
{
    if (c >= 65 && c <= 90)
        return (1);
    return (0);
}

int is_low_letter(char c)
{
    if (c >= 97 && c <= 122)
        return (1);
    return (0);
}

int is_number(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
