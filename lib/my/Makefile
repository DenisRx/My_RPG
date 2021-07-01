##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make
##

SRC		=	src/printf/get_flags.c				\
			src/printf/my_printf.c				\
			src/printf/not_handled.c			\
			src/printf/print_string.c			\
			src/printf/print_char.c				\
			src/printf/print_int.c				\
			src/printf/print_double.c			\
			src/printf/print_pointer.c			\
			src/printf/print_custom.c			\
			src/printf/flags_handle.c			\
			src/lib/my_putchar.c				\
			src/lib/my_putstr.c					\
			src/lib/concat_params.c				\
			src/lib/convert_base.c				\
			src/lib/my_calloc.c					\
			src/lib/my_compute_factorial_it.c	\
			src/lib/my_compute_factorial_rec.c	\
			src/lib/my_compute_power_it.c		\
			src/lib/my_compute_power_rec.c		\
			src/lib/my_compute_square_root.c	\
			src/lib/my_evil_str.c				\
			src/lib/my_find_prime_sup.c			\
			src/lib/my_getnbr_base.c			\
			src/lib/my_getnbr.c					\
			src/lib/my_isalphanum.c				\
			src/lib/my_isneg.c					\
			src/lib/my_is_prime.c				\
			src/lib/my_print_alpha.c			\
			src/lib/my_print_comb2.c			\
			src/lib/my_print_comb.c				\
			src/lib/my_print_combn.c			\
			src/lib/my_print_digits.c			\
			src/lib/my_print_revalpha.c			\
			src/lib/my_putnbr_base.c			\
			src/lib/my_put_nbr.c				\
			src/lib/my_revstr.c					\
			src/lib/my_showmem.c				\
			src/lib/my_showstr.c				\
			src/lib/my_show_word_array.c		\
			src/lib/my_sizeof.c					\
			src/lib/my_sort_int_array.c			\
			src/lib/my_sortstr.c				\
			src/lib/my_strcapitalize.c			\
			src/lib/my_strcat.c					\
			src/lib/my_strcmp.c					\
			src/lib/my_strcpy.c					\
			src/lib/my_strdup.c					\
			src/lib/my_str_isalpha.c			\
			src/lib/my_str_islower.c			\
			src/lib/my_str_isnum.c				\
			src/lib/my_str_isprintable.c		\
			src/lib/my_str_isupper.c			\
			src/lib/my_strlen.c					\
			src/lib/my_strlowcase.c				\
			src/lib/my_strncat.c				\
			src/lib/my_strncmp.c				\
			src/lib/my_strncpy.c				\
			src/lib/my_strstr.c					\
			src/lib/my_str_to_word_array.c		\
			src/lib/my_strupcase.c				\
			src/lib/my_swap.c					\
			src/lib/utils.c						\
			src/lib/is_neg.c					\
			src/lib/nb_size.c 					\
			src/lib/my_getstr.c					\
			src/lib/my_str_start_with.c

OBJ				=		$(SRC:.c=.o)

NAME            =       libmy.a

CFLAGS          =       -Wall -Wextra

LDFLAGS 		=		-L./lib

LDLIBS          =       -lmy

CPPFLAGS        =       -I ./include/ -g

LIB				=		lib/libmy.a

RM              =       rm -f

TEST	=	tests/tests_printf.c

TFLAGS	=	--coverage -lcriterion

INCLUDE =	-I ./include/

all:	$(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)
		cp include/my.h ../../include
		cp -f $(NAME) ..

$(LIB):
		make -C lib/my
		make -C lib/my fclean

clean:
		@echo "Cleaning files..."
		$(RM) -r $(OBJ)
		$(RM) vgcore.* *~ src/*~ include/*~
		$(RM) vgcore.* *.gc* src/*.gc* src/printf/*.gc* src/lib/*.gc*

tests_run:
		@echo "Building tests..."
		@gcc -o unit_tests $(SRC) $(TEST) $(INCLUDE) $(TFLAGS) $(LIBARG)
		@echo "Starting tests..."
		@./unit_tests

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all tests_run clean fclean re
