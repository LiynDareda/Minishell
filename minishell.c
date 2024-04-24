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

void	lexer(t_shell *shell, char **envp)
{
	t_index	index;

	index.i = 0;
	shell->cmdtab = ft_split(shell->line, '|');
	shell->env = get_path(envp);
	while (shell->cmdtab[index.i])
	{
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
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	t_cmd		*cmd;
	t_simplecmd	*simplecmd;

	argc += 0;
	argv += 0;
	if (argc > 1)
		exit(0);
	shell = malloc(sizeof(t_shell));
	if (!shell)
		ft_exit(0);
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		ft_exit(0);
	simplecmd = malloc(sizeof(t_simplecmd));
	if (!simplecmd)
		ft_exit(0);
	shell->cmd = cmd;
	shell->cmd->simplecmd = simplecmd;
	shell->line = ft_readline("minishell$ ");
	while (shell->line > 0)
	{
		if (is_valid_line(shell->line)) 
		{
			add_history(shell->line);
			lexer(shell, envp);
		}
		shell->line = ft_readline("minishell$ ");
	}
	return (0);
}
