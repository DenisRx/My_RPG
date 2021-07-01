/*
** EPITECH PROJECT, 2020
** my_isalphanum
** File description:
** Check if char is alphanum
*/

int my_isalphanum(char c)
{
    if (c == ' ' || c == '\t')
        return (0);
    return (1);
}
