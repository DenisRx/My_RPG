/*
** EPITECH PROJECT, 2020
** my_headers
** File description:
** my header
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define ABS(x) ((x < 0) ? -x : x)
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)

int my_compute_factorial_it(int);
int my_compute_factorial_rec(int);
int my_compute_power_it(int, int);
long my_compute_power_rec(int, int);
int my_compute_square_root(int);
char *my_evil_str(char *);
int my_find_prime_sup(int);
int my_get_indexof(char, char const *);
long my_getnbr_base(char const *, char const *);
int my_getnbr(char const *);
int my_isalphanum(char);
int my_isneg(int);
int my_is_prime(int);
int my_print_alpha(void);
void my_print_nb(char);
int my_print_comb(void);
int my_print_digits(void);
void my_print_revalpha(void);
void my_putchar(char c);
int my_putnbr_base(int, char const *);
void my_put_nbr(int);
int my_putstr(char const *, int);
char *my_revstr(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
int my_sizeof(char * const *);
void my_sort_int_array(int *, int);
char **my_sortstr(char **, int);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char *);
char *my_strupcase(char *);
void my_swap(int *, int *);
void my_swap_str(char **, char **);
int count_char(char const *);
int is_low_letter(char);
int is_number(char);
int is_up_letter(char);
char *concat_params(int, char **);
int my_strbase_tobase(char *, long, char const *, int);
int my_show_word_array(char * const *);
char *my_strdup(char const *);
char **my_str_to_word_array(char const *, char *);
char *my_calloc(int, char);
char *convert_base(char const *, char const *, char const *);
int my_power(int, int);
int calculate_nb(int, int [10], int);
void my_printnb(int, int, int);
void my_printnbn(int, int, int);
int *my_prepend(int *, int, int, int);
void my_prepend_append(int *, int, int, int);
void check_ascii(int, char **, int);
int count_word(char const *, char *);
char *get_indexrange(char *, char const *, int, int);
char *get_string(char const *, int, int);
int my_getnbr_v2(char *);
int is_neg(char *);
int nb_size(int nb);
char *my_getstr(long nb);
int my_printf(char *, ...);
int flag_contains(char *, char *);
int my_str_start_with(const char *src, const char *str);