/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:05:00 by lbarlett          #+#    #+#             */
/*   Updated: 2024/04/29 13:18:31 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(t_shell *shell, char **envp)
{
	t_index	p;
	pid_t	pid;

	p.i = -1;
	while (shell->cmdtab[++p.i])
	{
		pid = fork();
		if (pid == -1)
			ft_error(2);
		if (pid == 0)
			execve(shell->cmd->simplecmd->path,
				shell->cmd->simplecmd->args, envp);
		else
		{
			waitpid(pid, NULL, 0);
			printf("DIO CANE\n");
		}
	}
}
