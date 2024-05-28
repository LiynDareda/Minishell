/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:09:58 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/27 14:08:31 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_infile(t_shell *shell, int i, int *j)
{
	int	apex;

	apex = 0;
	shell->cmdtab[i][*j] = ' ';
	while (shell->cmdtab[i][*j] == ' ' && shell->cmdtab[i][*j] != 34
			&& shell->cmdtab[i][*j] != 39)
		(*j)++;
	if (shell->cmdtab[i][*j] == 34 || shell->cmdtab[i][*j] == 39)
	{
		apex = 1;
		shell->cmdtab[i][*j] = ' ';
		(*j)++;
	}
	shell->cmd->io[0] = ft_strdup(shell->cmdtab[i] + *j, apex);
	while (shell->cmdtab[i][*j] != ' ' && shell->cmdtab[i][*j])
	{
		shell->cmdtab[i][*j] = ' ';
		(*j)++;
	}
}

static void	copy_outfile(t_shell *shell, int i, int *j)
{
	int	apex;

	apex = 0;
	shell->cmdtab[i][*j] = ' ';
	while (shell->cmdtab[i][*j] == ' ' && shell->cmdtab[i][*j] != 34
			&& shell->cmdtab[i][*j] != 39)
		(*j)++;
	if (shell->cmdtab[i][*j] == 34 || shell->cmdtab[i][*j] == 39)
	{
		apex = 1;
		shell->cmdtab[i][*j] = ' ';
		(*j)++;
	}
	shell->cmd->io[1] = ft_strdup(shell->cmdtab[i] + *j, apex);
	while (shell->cmdtab[i][*j] != ' ' && shell->cmdtab[i][*j])
	{
		shell->cmdtab[i][*j] = ' ';
		(*j)++;
	}
}

static void	check_infile_outfile(t_shell *shell)
{
	t_index	id;

	id.i = 0;
	id.k = 0;
	while (shell->cmdtab[id.i])
	{
		id.j = 0;
		while (shell->cmdtab[id.i][id.j])
		{
			id.k = 0;
			if (shell->cmdtab[id.i][id.j] == '<'
					&& shell->cmdtab[id.i][id.j + 1] != '<')
				copy_infile(shell, id.i, &id.j);
			else if (shell->cmdtab[id.i][id.j] == '>')
				copy_outfile(shell, id.i, &id.j);
			id.j++;
		}
		id.i++;
	}
}

void	lexer(t_shell *shell, char **envp)
{
	t_index	id;

	id.i = -1;
	id.k = 0;
	change_space_to_snake(shell->line);
	shell->cmdtab = ft_split(shell->line, '|');
	expand_var(shell->cmdtab, shell);
	shell->path = get_env(envp);
	check_infile_outfile(shell);
	// printf("infile: %s\n", shell->cmd->io[0]);
	// printf("outfile: %s\n", shell->cmd->io[1]);
	// printf("cmdtab: %s\n", shell->cmdtab[0]);c
	while (shell->cmdtab[++id.i])
	{
		id.j = 0;
		shell->cmd->scmd->args = ft_split(shell->cmdtab[id.i], ' ');
		change_snake_to_space(shell->cmd->scmd->args);
		shell->cmd->scmd->path
			= valid_command(shell->cmd->scmd->args, shell->path);
		id.k = check_builtin1(shell, envp, &id.j);
		if (!shell->cmd->scmd->path && id.k == 1)
			write(1, "Command not found\n", 18);
	}
	executor(shell, envp, id.i);
}
