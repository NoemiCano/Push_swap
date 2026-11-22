#Nombre temporal para manejarlo mas comodamente
NAME = pushlib.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_push.c ft_swap.c ft_rotate.c ft_reverse_rotate.c \
	   ft_stack_functions.c libft/ft_putstr_fd.c ft_assign_index.c

#!!Temporal, borrar despues!!
SRCS += ft_print_stacks.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_push_swap.h libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

libft/%.o: libft/%.c libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
