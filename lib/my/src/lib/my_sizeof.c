/*
** EPITECH PROJECT, 2020
** my_sizeof
** File description:
** Count size of array
*/

int my_sizeof(char * const *array)
{
    int i = 0;

    while (array[i] != 0) {
        i++;
    }
    return (i);
}
