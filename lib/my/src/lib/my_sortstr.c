/*
** EPITECH PROJECT, 2020
** my_sortstr
** File description:
** Sort list of string
*/

int my_strcmp(char const *s1, char const *s2);

void my_swap_str(char **a, char **b);

void check_ascii(int i, char **str, int n)
{
    for (int x = i; x < n; x++) {
        if (my_strcmp(str[x], str[x+1]) > 0) {
            my_swap_str(&str[x], &str[x+1]);
        }
    }
}

char **my_sortstr(char **str, int n)
{
    for (int i = 0; i < n; i++) {
        check_ascii(i, str, n);
    }
    return str;
}
