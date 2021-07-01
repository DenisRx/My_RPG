/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** utils
*/

#include "global.h"

char *my_trim(char *string)
{
    char *end;

    while (*string == ' ')
        string++;
    if (*string == 0)
        return string;
    end = string + my_strlen(string) - 1;
    while (end > string && *end == ' ')
        end--;
    return (string);
}

void my_trimarr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        arr[i] = my_trim(arr[i]);
    }
}

char *get_tag_name(char *line)
{
    char *tag_name = my_strdup(line);
    char *base_ptr = tag_name;
    char *result;
    int i = 1;

    if (line[0] != '<')
        return (NULL);
    tag_name++;
    while (tag_name[i] != ' ' && tag_name[i] != '>')
        i++;
    tag_name[i] = '\0';
    result = my_strdup(tag_name);
    free(base_ptr);
    return (result);
}

char *get_char_until(char *str, char c)
{
    char *result = my_strdup(str);
    char *base_ptr = result;
    char *ret;
    int i = 0;

    while (result[i] != c)
        i++;
    result[i] = '\0';
    ret = my_strdup(result);
    free(base_ptr);
    return (ret);
}

int is_tag_end(char *name, char **lines, int pos)
{
    char *tag_name = get_tag_name(lines[pos]);
    int len = my_strlen(lines[pos]);

    if (len > 0 && lines[pos][len - 2] == '/') {
        return (1);
    }
    if (tag_name == NULL || tag_name[0] != '/')
        return (0);
    return (my_strcmp(tag_name + 1, name) == 0);
}