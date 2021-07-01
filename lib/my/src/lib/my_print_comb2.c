/*
** EPITECH PROJECT, 2020
** my_print_comb2
** File description:
** Print int
*/

void my_putchar(char c);

void my_print_nb(int a)
{
    int i = 0;

    if (a < 10) {
        my_putchar(48);
        my_putchar(a + 48);
        return;
    }
    while (i < 100) {
        if (a >= i && a < i + 10) {
            my_putchar((i/10)+48);
            my_putchar(a-i+48);
        }
        i += 10;
    }
}
