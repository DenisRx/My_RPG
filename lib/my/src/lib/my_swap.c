/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** Swap 2 pointer
*/

void my_swap(int *a, int *b)
{
    int temp_a;
    int temp_b;

    temp_a = *a;
    temp_b = *b;
    *a = temp_b;
    *b = temp_a;
}

void my_swap_str(char **a, char **b)
{
    char temp_a;
    char temp_b;

    temp_a = **a;
    temp_b = **b;
    **a = temp_b;
    **b = temp_a;
}
