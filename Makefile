NAME = libftprintf.a

AR = ar rc

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = -I ./

SOURCE = 	ft_printf.c \
			ft_parsing.c \
			free_struct.c \
			get_specifier.c \
			get_value.c \
			ft_utils.c \
			ft_memchr.c \
			ft_itoa.c \
			ft_itoa_16.c \
			ft_atoi.c \
			ft_processor.c \
			calculate_int.c \
			calculate_unsigned.c \
			print.c \
			put.c

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