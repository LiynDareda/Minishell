/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:13:54 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/20 14:10:13 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_space_to_snake(char *line)
{
	t_index	id;

	id.i = -1;
	while (line[++id.i])
	{
		if (line[id.i] == 34 || line[id.i] == 39)
		{
			id.i++;
			while (line[id.i] != 34 && line[id.i] != 39 && line[id.i])
			{
				if (line[id.i] == ' ')
					line[id.i] = '_';
				id.i++;
			}
		}
	}
}

void	change_snake_to_space(char **line)
{
	t_index	id;

	id.i = -1;
	while (line[++id.i])
	{
		id.j = -1;
		while (line[id.i][++id.j])
		{
			if (line[id.i][id.j] == 34 || line[id.i][id.j] == 39)
			{
				id.j++;
				while (line[id.i][id.j] != 34 && line[id.i][id.j] != 39
					&& line[id.i][id.j])
				{
					if (line[id.i][id.j] == '_')
						line[id.i][id.j] = ' ';
					id.j++;
				}
			}
		}
	}
}

int	check_builtin1(t_shell *shell, char **envp, int *j)
{
	if (shell->cmdtab[1] != NULL)
		return (2);
	if (ft_strncmp(shell->cmdtab[0], "export", 6) == 0)
	{
		if (shell->cmd->scmd->args[*j + 1] == NULL)
			return (export(NULL, envp));
		while (shell->cmd->scmd->args[++*j])
			export(shell->cmd->scmd->args[*j], envp);
		return (0);
	}
	if (ft_strncmp(shell->cmdtab[0], "unset", 5) == 0
		&& shell->cmdtab[1] == NULL)
	{
		while (shell->cmd->scmd->args[++*j])
			unset(shell->cmd->scmd->args[*j], envp);
		return (0);
	}
	// if (ft_strncmp(shell->cmd->scmd->args[*j], "cd", 2) == 0)
	// 	return (ft_change_dir(shell->cmd->scmd->args[++*j], shell, envp));
	if (ft_strncmp(shell->cmdtab[0], "exit", 4) == 0
		&& shell->cmdtab[1] == NULL)
		ft_quit(shell, 0, 1);
	return (1);
}

int	check_builtin2(t_shell *shell, char **envp, int j, int fd)
{
	if (ft_strncmp(shell->cmd->scmd->args[j], "echo", 4) == 0)
	{
		if (ft_strncmp(shell->cmd->scmd->args[++j], "-n", 2) == 0)
			ft_echo(shell->cmd->scmd->args, shell, 1, fd);
		else
			ft_echo(shell->cmd->scmd->args, shell, 0, fd);
		return (0);
	}
	if (ft_strncmp(shell->cmd->scmd->args[j], "env", 3) == 0)
		return (print_env(envp, fd));
	if (ft_strncmp(shell->cmd->scmd->args[j], "pwd", 3) == 0)
		return (pwd(envp, fd));
	return (1);
}

