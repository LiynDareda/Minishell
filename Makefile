# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 17:46:15 by mdella-r          #+#    #+#              #
#    Updated: 2024/05/10 17:46:15 by mdella-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = minishell.c minishell_utils.c error.c utils.c utils_II.c executor.c garbage_collector.c echo.c builtin.c export_utils.c expand_var.c lexer.c lexer_utils.c ctrl.c

NAME = minishell

COMPILE = gcc -g -Wall -Wextra -Werror

LIBFT_DIR = Libft/
LIBFT = Libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(COMPILE) -o $(NAME) $(OBJS) $(LIBFT) -lreadline -no-pie

clean:
	rm -f $(OBJS) $(BOBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all