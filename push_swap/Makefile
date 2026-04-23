NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c parsing_utils.c validation_utils.c stack.c \
		 operation_push.c operation_reverse.c operation_rotate.c \
		 operation_swap.c sort_small.c turk1.c turk2.c turk3.c turk4.c
OBJ = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	Make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	Make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	Make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re