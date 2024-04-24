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

	/*cat -e | grep uwu | ls
	0		1			2
	cat 
	-e
	right_path*/

void	lexer(t_shell *shell)
{
	t_index	index;

	index.i = 0;
	shell->cmdtab = ft_split(shell->line, '|');
	shell->env = get_env(shell->env);
	while (shell->cmdtab[index.i] != NULL)
	{
		shell->cmd->simplecmd->args = ft_split(shell->cmdtab[index.i], ' ');
		shell->cmd->simplecmd->path = valid_command(&shell->cmd->simplecmd->args[0], shell->env);
		if (!shell->cmd->simplecmd->path)
			ft_exit(0);
		printf("OK!\n");
		index.i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	argc += 0;
	argv += 0;
	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (0);
	shell->env = envp;
	shell->line = ft_readline("minishell$ ");
	while (shell->line > 0)
	{
		if (is_valid_line(shell->line)) 
		{
			add_history(shell->line);
			lexer(shell);
		}
		shell->line = ft_readline("minishell$ ");
	}
	return (0);
}
