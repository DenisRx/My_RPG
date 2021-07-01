/*
** EPITECH PROJECT, 2020
** my_print_comb
** File description:
** Print some numbers
*/

void my_putchar(char c);

void my_printnb(int a, int b, int c)
{
    my_putchar(a + 48);
    my_putchar(b + 48);
    my_putchar(c + 48);
    if (a != 7 || b != 8 || c != 9) {
        my_putchar(44);
        my_putchar(32);
    }
}

int my_print_comb(void)
{
    int first = 0;
    int second = 0;
    int third = 0;

    for (; third < 10; third++) {
        if (first < second && second < third) {
            my_printnb(first, second, third);
        }
        if (first < 8 && third == 9 && second < 9) {
            third = 0;
            second++;
        }
        if (second == 9 && third == 9 && first < 81) {
            first++;
            second = 0;
            third = 0;
        }
    }
    my_putchar(10);
    return (0);
}
