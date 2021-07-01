/*
** EPITECH PROJECT, 2020
** my_print_revalpha
** File description:
** Display alphabet desc
*/

void my_putchar(char c);

void my_print_revalpha(void)
{
    for (int i = 122; i >= 97; i -= 1) {
        my_putchar(i);
    }
}
