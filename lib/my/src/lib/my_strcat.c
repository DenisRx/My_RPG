/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** Concat two string
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    int total_len = dest_len + src_len;

    for (int i = dest_len; i < total_len; i++) {
        dest[i] = src[i - dest_len];
    }
    dest[total_len] = '\0';
    return dest;
}
