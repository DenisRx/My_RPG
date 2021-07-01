/*
** EPITECH PROJECT, 2020
** my_print_digits
** File description:
** Display digits
*/

void my_putchar(char c);

int my_print_digits(void)
{
    for (int i = 48; i <= 57; i++) {
        my_putchar(i);
    }
    return (0);
}
