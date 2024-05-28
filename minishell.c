/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:34:33 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/27 10:49:49 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_exit_sig = 0;

t_shell	*init_shell(void)
{
	t_shell	*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	if (!shell)
		ft_exit(1);
	shell->cmd = malloc(sizeof(t_cmd));
	if (!shell->cmd)
		ft_quit(shell, 2, 0);
	shell->cmd->scmd = malloc(sizeof(t_simplecmd));
	if (!shell->cmd->scmd)
		ft_quit(shell, 3, 0);
	shell->garbage = (t_garbage *)malloc(sizeof(t_garbage));
	if (!shell->garbage)
		ft_quit(shell, 4, 0);
	return (shell);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	t_cmd		*cmd;
	t_simplecmd	*scmd;

	argc += 0;
	argv += 0;
	if (argc > 1)
		ft_exit(0);
	shell = init_shell();
	shell->env = env_copy(envp);
	shell->line = ft_readline(ORANGE "minishell$ " DEFAULT, shell);
	while (shell->line > 0)
	{
		add_history(shell->line);
		if (is_valid_line(shell->line))
			lexer(shell, shell->env);
		shell->line = ft_readline(ORANGE "minishell$ " DEFAULT, shell);
	}
	ft_quit(shell, 0, 1);
	return (0);
}
