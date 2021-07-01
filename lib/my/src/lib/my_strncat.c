/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** Concat two string
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    int total_len = dest_len + src_len - nb;

    if (nb < 0)
        return (dest);
    for (int i = dest_len; i < total_len; i++) {
        dest[i] = src[i - dest_len];
    }
    return dest;
}
