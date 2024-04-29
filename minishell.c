/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:08:31 by espinell          #+#    #+#             */
/*   Updated: 2024/04/18 13:37:49 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer(t_shell *shell, char **envp)
void	lexer(t_shell *shell, char **envp)
{
	t_index	index;

	index.i = 0;
	shell->cmdtab = ft_split(shell->line, '|');
	shell->env = get_path(envp);
	while (shell->cmdtab[index.i])
	t_index	index;

	index.i = 0;
	shell->cmdtab = ft_split(shell->line, '|');
	shell->env = get_path(envp);
	while (shell->cmdtab[index.i])
	{
		shell->cmd->simplecmd->args = ft_split(shell->cmdtab[index.i], ' ');
		shell->cmd->simplecmd->path
			= valid_command(shell->cmd->simplecmd->args, shell->env);
		shell->cmd->simplecmd->args = ft_split(shell->cmdtab[index.i], ' ');
		shell->cmd->simplecmd->path
			= valid_command(shell->cmd->simplecmd->args, shell->env);
		if (!shell->cmd->simplecmd->path)
		{
			write(2, "Command not found\n", 18);
			free_mat(shell->cmd->simplecmd->args);
			free_mat(shell->cmdtab);
			return ;
		}
		index.i++;
		{
			write(2, "Command not found\n", 18);
			free_mat(shell->cmd->simplecmd->args);
			free_mat(shell->cmdtab);
			return ;
		}
		index.i++;
	}

	execute(shell, envp);
}

t_shell	*init_shell(void)
{
	t_shell	*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	if (!shell)
		ft_exit(0);
	shell->cmd = malloc(sizeof(t_cmd));
	if (!shell->cmd)
		ft_exit(0);
	shell->cmd->simplecmd = malloc(sizeof(t_simplecmd));
	if (!shell->cmd->simplecmd)
		ft_exit(0);
	return (shell);
}



int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	t_cmd		*cmd;
	t_simplecmd	*simplecmd;
	t_garbage	*garbage;

	argc += 0;
	argv += 0;
	if (argc > 1)
		exit(0);
	shell = init_shell();
	garbage = (t_garbage *)malloc(sizeof(t_garbage));
	shell->line = ft_readline("minishell$ ", garbage, shell);
	while (shell->line > 0)
	{
		if (is_valid_line(shell->line))
		{
			add_history(shell->line);
			lexer(shell, envp);
			lexer(shell, envp);
		}
		shell->line = ft_readline("minishell$ ", garbage, shell);
	}
	return (0);
}

