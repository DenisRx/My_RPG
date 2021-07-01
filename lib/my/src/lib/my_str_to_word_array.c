/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** Split string
*/

#include <stdlib.h>

char *my_calloc(int size, char c);

int my_strlen(char const *str);

int need_split(char c, char *split_chars)
{
    for (int i = 0; split_chars[i] != '\0'; i++) {
        if (split_chars[i] == c)
            return (1);
    }
    return (0);
}

char *get_indexrange(char *dest, char const *str, int start, int end)
{
    int len = end - start;

    for (int i = 0; i < len; i++) {
        dest[i] = str[start];
        start++;
    }
    return (dest);
}

char *get_string(char const *str, int start, int end)
{
    char *tmp;

    tmp = my_calloc(end - start + 1, '\0');
    get_indexrange(tmp, str, start, end);
    return (tmp);
}

int count_word(char const *str, char *split_chars)
{
    int len = my_strlen(str);
    int count = 0;
    int start_index = 0;

    for (int i = 0; i < len; i++) {
        if (need_split(str[i], split_chars) && i - start_index >= 1) {
            start_index = i + 1;
            count++;
        }
        if (need_split(str[i], split_chars) && i - start_index < 1)
            start_index = i + 1;
    }
    if (len - start_index >= 1)
        count += 2;
    else
        count++;
    return (count);
}

char **my_str_to_word_array(char const *str, char *split_chars)
{
    int len = my_strlen(str);
    char **result = malloc(8 * count_word(str, split_chars));
    int start_index = 0;
    int array_len = 0;
    int array_index = 0;

    for (int i = 0; i < len; i++) {
        if (need_split(str[i], split_chars) && i - start_index >= 1) {
            array_len += i - start_index;
            result[array_index] = get_string(str, start_index, i);
            start_index = i + 1;
            array_index++;
        }
        if (need_split(str[i], split_chars) && i - start_index < 1)
            start_index = i + 1;
    }
    if (len - start_index >= 1)
        result[array_index++] = get_string(str, start_index, len);
    result[array_index] = NULL;
    return (result);
}
