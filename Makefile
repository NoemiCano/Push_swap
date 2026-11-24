#Nombre temporal para manejarlo mas comodamente
NAME = pushlib.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	ft_push.c \
		ft_swap.c \
		ft_rotate.c \
		ft_reverse_rotate.c \
		ft_stack_functions.c \
		disorder_index.c \
		insertion.c \
		intermediate.c \
		parse_input.c \
		push_swap.c \
		utils.c

#!!Temporal, borrar despues!!
SRCS += ft_print_stacks.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean:
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
