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

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>
# define ORANGE "\001\033[38;5;208m\002"
# define DEFAULT "\001\033[0m\002"

extern int	g_exit_sig;

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
	t_simplecmd		*scmd;
	char			*io[2];
}			t_cmd;

typedef struct shell
{
	t_cmd		*cmd;
	t_garbage	**garbage;
	char		*line;
	char		**path;
	char		**env;
	char		**cmdtab;	
}				t_shell;

typedef struct index
{
	int		i;
	int		j;
	int		k;
	pid_t	pid;
	int		**fd;
}			t_index;

typedef struct echo
{
	int		i;
	int		j;
	int		flag;
	char	apex;
}			t_echo;

size_t		ft_name(char *str);
t_garbage	*ft_lstnew(void *line);
char		**get_env(char **env);
char		**env_copy(char **envp);
char		*valid_command(char **command, char **env);
char		*ft_check_var(char *str, int i, t_shell *shell);
char		*ft_readline(char *str, t_shell *shell);
int			matlen(char **mat);
int			free_mat(char **mat);
int			pwd(char **envp, int fd);
int			print_env(char **envp, int fd);
int			is_valid_line(char *line);
int			free_pfd(int **pfd, int l);
int			ft_idchar(char *args, char c);
int			unset(char *args, char **envp);
int			export(char *args, char **envp);
int			ft_var_update(char *args, char *envp);
int			check_builtin1(t_shell *shell, char **envp, int *j);
int			ft_echo(char **args, t_shell *shell, int flag, int fd);
int			check_builtin2(t_shell *shell, char **envp, int j, int fd);
void		ctrl_c(int sig);
void		ctrl_d(int sig);
void		ft_exit(int id);
void		ctrl_bslash(int sig);
void		ft_putstr(char *str);
void		free_shell(t_shell *shell);
void		change_space_to_snake(char *line);
void		change_snake_to_space(char **line);
void		lexer(t_shell *shell, char **envp);
void		expand_var(char **cmd, t_shell *shell);
void		wait_and_free(pid_t pid, int **pfd, int i);
void		ft_error(t_shell *shell, int id, int flag);
void		executor(t_shell *shell, char **envp, int i);
void		add_env(char *str, char **envp, int i, int *j);
void		ft_lstadd_back(t_garbage **lst, t_garbage *new);
void		ft_lstclear(t_garbage **lst, void (*del)(void*));
void		garbage_collector(t_shell *shell, int flag);
void		ft_quit(t_shell *shell, int signal, int flag);

#endif