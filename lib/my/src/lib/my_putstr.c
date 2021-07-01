/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Write string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str, int fd)
{
    return (write(fd, str, my_strlen(str)));
}
