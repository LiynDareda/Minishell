/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:15:14 by espinell          #+#    #+#             */
/*   Updated: 2024/05/09 12:15:14 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"

void	lexer(t_shell *shell, char **envp)
{
	t_index	index;

	index.i = 0;
	index.j = 0;
	shell->cmdtab = ft_split(shell->line, '|');
	shell->path = get_env(envp);
	//check_cmdtab(shell->cmdtab);
	while (shell->cmdtab[index.i])
	{
		shell->cmd->simplecmd->args = ft_split(shell->cmdtab[index.i], ' ');
		shell->cmd->simplecmd->path
			= valid_command(shell->cmd->simplecmd->args, shell->path);
		if (ft_strncmp(shell->cmdtab[0], "export", 6) == 0)
		{
			while (shell->cmd->simplecmd->args[++index.j])
				export(shell->cmd->simplecmd->args[index.j], envp);
			return ;
		}
		if (ft_strncmp(shell->cmdtab[0], "env", 3) == 0)
		{
			print_env(envp);
			return ;
		}
		if (ft_strncmp(shell->cmdtab[0], "pwd", 3) == 0)
		{
			pwd(envp);
			return ;
		}
		if (ft_strncmp(shell->cmdtab[0], "unset", 5) == 0)
		{
			while (shell->cmd->simplecmd->args[++index.j])
				unset(shell->cmd->simplecmd->args[index.j], envp);
			return ;
		}
		if (ft_strncmp(shell->cmdtab[0], "exit", 4) == 0)
			ft_quit(shell, shell->garbage, 1);
		if (!shell->cmd->simplecmd->path)
		{
			write(2, "Command not found\n", 18);
			free_mat(shell->cmd->simplecmd->args);
			free_mat(shell->cmdtab);
			return ;
		}
		index.i++;
	}
	executor(shell, envp, index.i);
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
	static int	signal;

	argc += 0;
	argv += 0;
	if (argc > 1)
		exit(0);
	shell = init_shell();
	shell->env = env_copy(envp);
	garbage = (t_garbage *)malloc(sizeof(t_garbage));
	shell->line = ft_readline(ORANGE "minishell$ " DEFAULT, garbage, shell);
	while (shell->line > 0)
	{
		if (is_valid_line(shell->line))
		{
			add_history(shell->line);
			lexer(shell, shell->env);
		}
		shell->line = ft_readline(ORANGE "minishell$ " DEFAULT, garbage, shell);
	}
	return (0);
}