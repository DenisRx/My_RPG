/*
** EPITECH PROJECT, 2020
** load_file_in_mem
** File description:
** Load file in char pointer
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "global.h"

int is_file_existing(const char *filepath)
{
    struct stat stats;

    return (stat(filepath, &stats) == 0);
}

int get_file_size(char const *filepath)
{
    struct stat stats;

    stat(filepath, &stats);
    return (stats.st_size);
}

char *load_file_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    int size = get_file_size(filepath);
    char *buffer = my_calloc(size + 2, '\0');

    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}

int count_rows(char *buffer)
{
    int count = 0;
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            count++;
        i++;
    }
    if (buffer[i - 1] != '\n')
        count++;
    return (count);
}

int *convert_buffer(char *buffer)
{
    int length = my_strlen(buffer) - count_rows(buffer);
    int *map = malloc(sizeof(int) * length);
    int index = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != '\n')
            map[index++] = buffer[i] - 48;
    }
    return (map);
}