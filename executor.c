/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:05:00 by lbarlett          #+#    #+#             */
/*   Updated: 2024/05/02 14:57:30 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_command(t_shell *shell, int i, int **fd, char **envp)
{
	int	filefd;
	char **env;

	shell->cmd->simplecmd->args = ft_split(shell->cmdtab[i], ' ');
	env = get_env(envp);
	shell->cmd->simplecmd->path
		= valid_command(shell->cmd->simplecmd->args, env);
	if (i == 0)
	{
		(void)(dup2(fd[i][1], 1) + close(fd[i][0]));
		// if (infile esiste)
		// {
		// 	filefd = open(shell->cmd->io[0], O_RDONLY);
		// 	dup2(filefd, 0);
		// }
	}
	else
	{
		(void)(dup2(fd[i][1], 1) + close(fd[i][0]) +
			dup2(fd[i - 1][0], 0) + close(fd[i - 1][1]));
	}
	execve(shell->cmd->simplecmd->path,
		shell->cmd->simplecmd->args, envp);
		exit (0);
}

static void	execute_last_command(t_shell *shell, int i, int **fd, char **envp)
{
	int	filefd;
	char **env;

	shell->cmd->simplecmd->args = ft_split(shell->cmdtab[i], ' ');
	env = get_env(envp);
	shell->cmd->simplecmd->path
		= valid_command(shell->cmd->simplecmd->args, env);
	dup2(fd[i - 1][0], 0);
	close(fd[i - 1][1]);
	// if (outfile esiste)
	// {
	// 	filefd = open(shell->cmd->io[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// 	dup2(filefd, 1);
	// }
	execve(shell->cmd->simplecmd->path,
		shell->cmd->simplecmd->args, envp);
		exit (0);
}

void	executor(t_shell *shell, char **envp, int i)
{
	t_index	p;
	pid_t	pid;
	int		**fd;

	p.i = -1;
	p.j = -1;
	p.k = 0;
	if (ft_strncmp(shell->cmdtab[0], "echo", 4) == 0)
	{
		shell->env = envp;
		ft_echo(shell->cmdtab[0], shell);
		return ;
	}
	if (i == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(shell->cmd->simplecmd->path,
				shell->cmd->simplecmd->args, envp);
			exit (0);
		}
		else
		{
			waitpid(pid, NULL, 0);
			return ;
		}
		return ;
	}
	else
		fd = malloc(sizeof(int *) * (i - 1));
	while (++p.j < i - 1)
		fd[p.j] = malloc(sizeof(int) * 2);
	while (++p.i < i - 1)
	{
		if (pipe(fd[p.i]) == -1)
			ft_error(1);
		pid = fork();
		if (pid == -1)
			ft_error(2);
		if (pid == 0)
			execute_command(shell, p.i, fd, envp);
		else if (p.i < i - 1)
			close(fd[p.i][1]);
	}
	pid = fork();
	if (pid == -1)
		ft_error(2);
	if (pid == 0)
		execute_last_command(shell, p.i, fd, envp);
	else
		waitpid(pid, NULL, 0);
}