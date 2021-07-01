/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** Show every word passed in params
*/

char *concat_params(int argc, char **argv);

int my_sizeof(char * const *array);

int my_showstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int len = my_sizeof(tab);

    for (int i = 0; i < len; i++) {
        my_showstr(tab[i]);
        my_showstr("\n");
    }
    return (0);
}
