/*
** EPITECH PROJECT, 2020
** my_showstr
** File description:
** Some print custom function
*/

int count_char(char const *str);

int my_str_isprintable(char const *str);

int my_putnbr_base(int nbr, char const *base);

void my_putchar(char c);

int my_showstr(char const *str)
{
    int len = count_char(str);

    for (int i = 0; i < len; i++) {
        if (my_str_isprintable(&str[i])){
            my_putchar(str[i]);
        } else {
            my_putchar('\\');
            my_putnbr_base(str[i], "0123456789ABCDEF");
        }
    }
    return (0);
}
