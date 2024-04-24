/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:13:35 by espinell          #+#    #+#             */
/*   Updated: 2024/04/24 14:36:26 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_simplecmd
{
	char	*path;
	char	**args;
}			t_simplecmd;

typedef struct s_cmd
{
	t_simplecmd		*simplecmd;
	char			io[2][255];
}			t_cmd;

typedef struct shell
{
	t_cmd	*cmd;
	char	*line;
	char	**env;
	char	**cmdtab;	
}			t_shell;

typedef struct index
{
	int		i;
	int		j;
	int		k;
}			t_index;

char	*ft_readline(char *prompt);
char	*valid_command(char **command, char **env);
char	**get_path(char **env);
int		is_valid_line(char *line);
void	lexer(t_shell *shell, char **envp);
void	ft_error(int id);
void	ft_exit(int id);
int		free_mat(char **mat);

#endif