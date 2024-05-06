/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:13:35 by espinell          #+#    #+#             */
/*   Updated: 2024/05/06 13:08:21 by marvin           ###   ########.fr       */
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
# include <fcntl.h>

typedef struct s_garbage
{
	char				*line;
	struct s_garbage	*next;
}			t_garbage;

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

typedef struct echo
{
	int		i;
	int		flag;
	char	apex;
}			t_echo;

t_garbage	*ft_lstnew(void *line);
char		**get_env(char **env);
char		*valid_command(char **command, char **env);
char		*ft_readline(char *str, t_garbage *garbage, t_shell *shell);
int			free_mat(char **mat);
int			is_valid_line(char *line);
void		ft_exit(int id);
void		ft_error(int id);
void    	pwd(char **envp);
void    	print_env(char **envp);
void		free_shell(t_shell *shell);
void    	export(char *args, char **envp);
void		lexer(t_shell *shell, char **envp);
void		ft_echo(char *args, t_shell *shell);
void		executor(t_shell *shell, char **envp, int i);
void		ft_lstadd_back(t_garbage **lst, t_garbage *new);
void		ft_lstclear(t_garbage **lst, void (*del)(void*));
void		garbage_collector(t_garbage **garbage, t_shell *shell);

#endif