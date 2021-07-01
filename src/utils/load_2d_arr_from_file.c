/*
** EPITECH PROJECT, 2020
** load_2d_arr_from_file
** File description:
** load_2d_arr_from_file
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "protos.h"

int nb_size(int nb)
{
    int i = 0;
    while (nb > 0) {
        nb = nb / 10;
        i++;
    }
    return (i);
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    char *file_content = load_file_in_mem(filepath);
    char *pt = file_content;
    char **arr = mem_alloc_2d_array(nb_rows, nb_cols);
    int arr_index = 0;
    char *tmp = my_calloc((nb_cols + 1) * sizeof(char), '\0');
    int tmp_index = 0;

    for (int i = 0; file_content[i] != '\0'; i++) {
        if (i > 0 && i % nb_cols == 0) {
            tmp[nb_cols] = 0;
            arr[arr_index++] = tmp;
            tmp = my_calloc((nb_cols + 1) * sizeof(char), '\0');
            tmp_index = 0;
            file_content = file_content + 1;
        }
        tmp[tmp_index++] = file_content[i];
    }
    tmp[tmp_index++] = 0;
    arr[arr_index] = tmp;
    free(pt);
    return (arr);
}