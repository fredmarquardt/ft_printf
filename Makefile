CC = cc
CFLAGS = -Wall -Werror -Wextra
SOURCE = ft_printf.c ft_print_hex.c ft_print_utils.c ft_print_ptr.c
OBJ = $(SOURCE:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): objfiles
	ar -rcv libftprintf.a $(OBJ)

objfiles:
	$(CC) $(CFLAGS) -c $(SOURCE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
