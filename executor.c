/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:36:03 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/27 14:49:03 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_one_command(t_shell *shell, char **envp)
{
	int		filefd;
	char	**env;

	signal(SIGQUIT, ctrl_bslash);
	if (shell->cmd->io[0] != NULL)
	{
		filefd = open(shell->cmd->io[0], O_RDONLY);
		dup2(filefd, 0);
	}
	shell->cmd->scmd->args = ft_split(shell->cmdtab[0], ' ');
	env = get_env(envp);
	if (check_builtin2(shell, envp, 0, 1) == 0)
		ft_quit(shell, 13, 0);
	shell->cmd->scmd->path = valid_command(shell->cmd->scmd->args, env);
	execve(shell->cmd->scmd->path, shell->cmd->scmd->args, envp);
	ft_quit(shell, 14, 0);
}

static void	execute_command(t_shell *shell, int i, int **fd, char **envp)
{
	int		filefd;
	char	**env;

	signal(SIGQUIT, ctrl_bslash);
	if (i == 0)
	{
		(void)(dup2(fd[i][1], 1) + close(fd[i][0]));
		if (shell->cmd->io[0] != NULL)
		{
			filefd = open(shell->cmd->io[0], O_RDONLY);
			dup2(filefd, 0);
		}
	}
	else
	{
		(void)(dup2(fd[i][1], 1) + close(fd[i][0]) +
			dup2(fd[i - 1][0], 0) + close(fd[i - 1][1]));
	}
	shell->cmd->scmd->args = ft_split(shell->cmdtab[i], ' ');
	env = get_env(envp);
	if (check_builtin2(shell, envp, 0, fd[i][1]) == 0)
		ft_quit(shell, 11, 0);
	shell->cmd->scmd->path = valid_command(shell->cmd->scmd->args, env);
	execve(shell->cmd->scmd->path, shell->cmd->scmd->args, envp);
	ft_quit(shell, 12, 0);
}

static void	execute_last_command(t_shell *shell, int i, int **fd, char **envp)
{
	int		filefd;
	char	**env;

	signal(SIGQUIT, ctrl_bslash);
	filefd = 1;
	if (shell->cmd->io[1] != NULL)
	{
		filefd = open(shell->cmd->io[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(filefd, 1);
	}
	dup2(fd[i - 1][0], 0);
	close(fd[i - 1][1]);
	shell->cmd->scmd->args = ft_split(shell->cmdtab[i], ' ');
	env = get_env(envp);
	if (!check_builtin2(shell, envp, 0, filefd))
		ft_quit(shell, 9, 0);
	shell->cmd->scmd->path = valid_command(shell->cmd->scmd->args, env);
	execve(shell->cmd->scmd->path, shell->cmd->scmd->args, envp);
	ft_quit(shell, 10, 0);
}

static void	pipex(t_shell *shell, char **envp, int i)
{
	t_index	p;

	p.i = -1;
	p.j = -1;
	p.fd = malloc(sizeof(int *) * (i - 1));
	while (++p.j < i - 1)
		p.fd[p.j] = malloc(sizeof(int) * 2);
	while (++p.i < i - 1)
	{
		if (pipe(p.fd[p.i]) == -1)
			ft_error(shell, 6, 0);
		p.pid = fork();
		if (p.pid == -1)
			ft_error(shell, 7, 0);
		if (p.pid == 0)
			execute_command(shell, p.i, p.fd, envp);
		else if (p.i < i - 1)
			close(p.fd[p.i][1]);
	}
	p.pid = fork();
	if (p.pid == -1)
		ft_error(shell, 8, 0);
	if (p.pid == 0)
		execute_last_command(shell, p.i, p.fd, envp);
	wait_and_free(p.pid, p.fd, p.i);
}

void	executor(t_shell *shell, char **envp, int i)
{
	t_index	p;

	if (i == 1)
	{
		p.pid = fork();
		if (p.pid == 0)
			execute_one_command(shell, envp);
		else
			waitpid(p.pid, NULL, 0);
		return ;
	}
	else
		pipex(shell, envp, i);
}
