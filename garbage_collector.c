/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:38:02 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/20 13:44:34 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_shell *shell)
{
	t_index	index;

	index.i = 0;
	index.j = 0;
	if (shell->cmdtab)
		free_mat(shell->cmdtab);
	if (shell->cmd->scmd->path)
		free(shell->cmd->scmd->path);
	if (shell->cmd->scmd->args)
		free_mat(shell->cmd->scmd->args);
	if (shell->cmd->scmd)
		free(shell->cmd->scmd);
	if (shell->cmd->io[0])
		free(shell->cmd->io[0]);
	if (shell->cmd->io[1])
		free(shell->cmd->io[1]);
}

t_garbage	*ft_lstnew(void *line)
{
	t_garbage	*new;

	new = (t_garbage *)malloc(sizeof(t_garbage));
	if (!new)
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_garbage **lst, t_garbage *new)
{
	t_garbage	*t;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	t = *lst;
	while (t->next != NULL)
		t = t->next;
	t->next = new;
}

void	ft_lstclear(t_garbage **lst, void (*del)(void*))
{
	t_garbage	*tmp;
	t_garbage	*current;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		del(current->line);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}

void	garbage_collector(t_shell *shell, int flag)
{
	ft_lstclear(shell->garbage, free);
	free_shell(shell);
	if (flag)
	{
		if (shell->env)
			free_mat(shell->env);
	}
}
