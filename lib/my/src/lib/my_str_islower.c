/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** Check if string contains alpha
*/

int is_up_letter(char c);

int is_low_letter(char c);

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_low_letter(str[i]) == 0)
            return (0);
    }
    return (1);
}
