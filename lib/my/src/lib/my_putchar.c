/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** Write a char
*/

#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);

void my_putchar(char c)
{
    write(1, &c, 1);
}
