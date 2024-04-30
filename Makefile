SRCS = minishell.c minishell_utils.c error.c split_utils.c

NAME = minishell

COMPILE = cc -Wall -Wextra -Werror -lreadline -g

LIBFT_DIR = libft/
LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(COMPILE) -o $(NAME) $(OBJS) $(LIBFT)



clean:
	rm -f $(OBJS) $(BOBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all