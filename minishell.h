/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:13:35 by espinell          #+#    #+#             */
/*   Updated: 2024/04/24 12:18:42 by lbarlett         ###   ########.fr       */
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
	t_simplecmd		simplecmd[255];
	char			io[2][255];
}			t_cmd;

typedef struct shell
{
	t_cmd	*cmd;
	char	*line;
	char	**env;
	char	*token;
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
char	**get_env(char **env);
int		is_valid_line(char *line);
void	lexer(t_shell *shell);
char	*my_get_env(char ***env, char ***cmd, char **envp, char *argv);
void	ft_error(int id);
void	ft_exit(int id);
int		free_mat(char **mat);

#endif