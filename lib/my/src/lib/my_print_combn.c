/*
** EPITECH PROJECT, 2020
** my_print_combn
** File description:
** Print some numbers
*/

void my_putchar(char c);

void my_printnbn(int a, int b, int c)
{
    my_putchar(a + 48);
    my_putchar(b + 48);
    my_putchar(c + 48);
    if (a != 7 || b != 8 || c != 9) {
        my_putchar(44);
        my_putchar(32);
    }
}
