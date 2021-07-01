/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** Check if string contains num
*/

int is_number(char c);

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_number(str[i]) != 0)
            return (0);
    }
    return (1);
}
