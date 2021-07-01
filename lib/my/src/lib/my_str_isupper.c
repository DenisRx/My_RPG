/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** Check if string contains alpha
*/

int is_up_letter(char c);

int is_low_letter(char c);

int my_str_isupper(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_up_letter(str[i]) != 0)
            return (0);
    }
    return (1);
}
