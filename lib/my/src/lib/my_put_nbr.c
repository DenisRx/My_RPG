/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** ok
*/

void my_putchar(char c);

void my_put_nbr(int nb)
{
    int temp;

    if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    if (nb >= 0 && nb < 10) {
        my_putchar(nb+48);
    } else {
        temp = (nb % 10);
        nb = nb / 10;
        if (nb < 0) {
            nb = -nb;
        }
        my_put_nbr(nb);
        if (temp < 0){
            temp = temp * -1;
        }
        my_putchar(temp+48);
    }
}
