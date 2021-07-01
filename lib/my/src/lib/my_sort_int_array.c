/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** Sort array of int (Deprecated)
*/

#include <stdio.h>

int my_strlen(char const *str);

int *my_prepend(int *array, int value, int index, int added)
{
    int newarr[added+1];
    int offset = 0;

    for (int i = 0; i <= added; i++) {
        if (index == i) {
            offset = 1;
            newarr[i] = value;
        } else {
            newarr[i] = array[i-offset];
        }
    }
    for (int i = 0; i < added+1; i++)
        array[i] = newarr[i];
    return array;
}

void my_prepend_append(int *array, int size, int value, int added)
{
    for (int i = 0; i < size; i++) {
        if (added == 0 || i + 2 > size || i + 1 > added) {
            array[i] = value;
            return;
        }
        if (value < array[i]) {
            array = my_prepend(array, value, i, added);
            return;
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    int new_array[size];
    int value;
    int added = 0;

    for (int i = 0; i < size; i++)
        new_array[i] = 0;
    for (int i = 0; i < size; i++) {
        value = array[i];
        my_prepend_append(new_array, size, value, added);
        added++;
    }
    for (int i = 0; i < size; i++)
        array[i] = new_array[i];
}
