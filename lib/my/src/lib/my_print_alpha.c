/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** Display alphabet asc
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    for (int i = 97; i <= 122; i += 1) {
        my_putchar(i);
    }
    return (0);
}
