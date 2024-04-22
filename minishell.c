/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:08:31 by espinell          #+#    #+#             */
/*   Updated: 2024/04/18 13:37:49 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void lexer(t_minishell *minishell)
{
	t_index	index;
	index.i = 0;
	minishell->cmdtab = ft_split(minishell->line, "|");
	while (minishell->cmdtab[i] != NULL)
	{
		minishell->cmd->simplecmd[i]->args = ft_split(minishell->cmdtab[i], " ");
		getcwd("PATH", );
		i++;
	}
	
	cat -e | grep uwu | ls
	0		1			2
	cat 
	-e
	right_path
}

int main(int argc, char **argv, char **envp)
{
    t_minishell *minishell;

    argc = 0;
    argv = 0;   
	minishell = malloc(sizeof(*t_minishell));
	if (!minishell)
		return;
	minishell->env = envp;
	minishell->line = ft_readline("minishell$ ");
    while (minishell.line > 0)
    {
		if(is_valid_line(minishell->line)) 
		{
			add_history(minishell->line);
			lexer(minishell);
			parser(minishell);
			executor(minishell);
		}
        minishell.line = ft_readline("minishell$ ");
    }
    return (0);
}