/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** save.c
*/

#include "global.h"

void write_line(int fd, int info)
{
    char *str = my_getstr(info);

    write(fd, str, my_strlen(str));
    write(fd, "\n", 1);
}

void write_in_file(game_t *game)
{
    int fd = open(FILE_PATH, O_CREAT | O_WRONLY, 0666);

    write_line(fd, game->hero->position.x);
    write_line(fd, game->hero->position.y);
    write_line(fd, game->map->id);
    write_line(fd, game->hero->lives);
    write_line(fd, game->hero->damage);
    write_line(fd, game->hero->level);
    write_line(fd, game->hero->xp);
    write_line(fd, game->hero->critical_chance);
    write_line(fd, game->hero->resistance);
    write_line(fd, game->inventory->remaining);
    write_line(fd, game->hero->color);
    for (node_t *node = game->inventory->boxes; node != NULL;
    node = node->next) {
        if (((box_t *)node->data)->element != NULL)
            write_line(fd, ((box_t *)node->data)->element->type);
    }
    close(fd);
}