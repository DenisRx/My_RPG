/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** Comparate two string based on first n bytes
*/

#include <stdio.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    char news1[n];
    char news2[n];

    for (int i = 0; s1[i] != '\0'; i++) {
        news1[i] = s1[i];
        news2[i] = s2[i];
    }

    if (news1 < news2)
        return (news1[0] - news2[0]);
    if (news1 > news2)
        return (news1[0] - news2[0]);
    return (0);
}
