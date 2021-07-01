/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** inner
*/

#include "global.h"

int get_inner_end(char *tag_name, char **lines, int i)
{
    char *current_tag;

    for (; lines[i] != NULL; i++) {
        if ((current_tag = get_tag_name(lines[i])) != NULL &&
        my_strcmp(tag_name, current_tag + 1) == 0) {
            break;
        }
    }
    free(current_tag);
    return (i);
}

int get_inner_len(char **lines, int start, int end)
{
    int len = 0;

    for (int i = start + 1; i < end; i++) {
        len += my_strlen(lines[i]);
    }
    return (len);
}

char *get_inner(char *tag_name, char **lines, int start)
{
    int end_index = get_inner_end(tag_name, lines, start);
    int len = get_inner_len(lines, start, end_index) + (end_index - start) + 1;
    char *inner_text = my_calloc(len, '\0');
    int inner_index = 0;

    for (int i = start + 1; i < end_index; i++) {
        for (int y = 0; lines[i][y] != '\0'; y++)
            inner_text[inner_index++] = lines[i][y];
        inner_text[inner_index++] = '\n';
    }
    return (inner_text);
}