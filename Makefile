# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 11:04:58 by lbarlett          #+#    #+#              #
#    Updated: 2024/05/02 14:36:41 by lbarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = minishell.c minishell_utils.c error.c utils.c executor.c garbage_collector.c echo.c builtin.c export_utils.c

NAME = minishell

COMPILE = cc -g -Wall -Wextra -Werror

LIBFT_DIR = Libft/
LIBFT = Libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(COMPILE) -o $(NAME) $(OBJS) $(LIBFT) -lreadline

clean:
	rm -f $(OBJS) $(BOBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all