NAME = libftprintf.a

AR = ar rc

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = -I ./

SOURCE = 	ft_utils.c \
			ft_parser.c \
			ft_printf.c \
			ft_processor.c \
			print_dwayne.c

OBJECT = $(SOURCE:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(NAME): $(OBJECT)
	$(AR) $(NAME) $(OBJECT)
	ranlib $(NAME)

clean:
	rm -f $(OBJECT) $(OBJECT_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re