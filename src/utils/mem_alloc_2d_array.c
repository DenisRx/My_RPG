/*
** EPITECH PROJECT, 2020
** mem_alloc_2d_array
** File description:
** Allocate 2d array
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "global.h"

int random_val(void)
{
    void *pt = malloc(1);
    int value = (long)pt;

    free(pt);
    return (value);
}

sfText *init_inv_text(char const *string)
{
    sfText *text = create_texts(MSG_FONT, (sfVector2f){550, 750}, sfWhite);

    sfText_setString(text, string);
    sfText_setCharacterSize(text, 25);
    return (text);
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **arr = malloc((nb_rows + 1) * sizeof(char *));
    char *tmp;

    for (int i = 0; i < nb_rows; i++) {
        tmp = my_calloc(nb_cols + 1, '\0');
        arr[i] = tmp;
    }
    return (arr);
}