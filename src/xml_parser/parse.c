/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** parse
*/

#include "global.h"

node_t *init_node(void)
{
    node_t *node = malloc(sizeof(node_t));

    node->next = NULL;
    node->data = NULL;
    return (node);
}

int is_one_line(char *line)
{
    int len = my_strlen(line);

    if (len > 0 && line[len - 2] == '/')
        return (0);
    return (1);
}

node_t *get_children(char *tag_name, char **lines, int start_i)
{
    int end_index = get_inner_end(tag_name, lines, start_i);
    int is_tag_opened = 0;
    char *cur_name;
    node_t *start = init_node();
    node_t *tmp = start;
    node_t *previous = NULL;

    for (int i = start_i + 1; i < end_index; i++) {
        if (is_tag_opened == 0 && (cur_name = get_tag_name(lines[i])) != NULL
        && cur_name[0] != '/') {
            previous != NULL ? previous->next = tmp : (void)previous;
            tmp->data = get_tag(cur_name, lines, i);
            previous = tmp;
            tmp = init_node();
            is_tag_opened = is_one_line(lines[i]);
        } else if (is_tag_end(cur_name, lines, i))
            is_tag_opened = 0;
    }
    return (start->data == NULL ? NULL : start);
}

tag_t *get_tag(char *tag_name, char **lines, int i)
{
    tag_t *tag;
    node_t *properties;

    tag = malloc(sizeof(tag_t));
    tag->name = tag_name;
    lines[i] += my_strlen(tag_name) + 2;
    tag->properties = NULL;
    if (lines[i][0] != '\0') {
        properties = get_properties(lines[i]);
        tag->properties = properties;
    }
    tag->inner = get_inner(tag_name, lines, i);
    if (!is_tag_end(tag_name, lines, i))
        tag->children = get_children(tag_name, lines, i);
    else
        tag->children = NULL;
    return (tag);
}

tag_t *parse_xml(char *path)
{
    char *buf = load_file_in_mem(path);
    char **lines = my_str_to_word_array(buf, "\n");
    tag_t *head = malloc(sizeof(tag_t));

    my_trimarr(lines);
    head = get_tag("HEAD", lines, 0);
    free(buf);
    return (head);
}