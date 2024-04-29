/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:25:53 by lbarlett          #+#    #+#             */
/*   Updated: 2024/04/29 14:17:08 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_shell *shell)
{
	t_index	index;

	index.i = 0;
	index.j = 0;
	if (shell->env)
		free(shell->env);
	if (shell->cmdtab)
		free_mat(shell->cmdtab);
	if (shell->cmd->simplecmd->path)
		free(shell->cmd->simplecmd->path);
	if (shell->cmd->simplecmd->args)
		free_mat(shell->cmd->simplecmd->args);
	if (shell->cmd->simplecmd)
		free(shell->cmd->simplecmd);
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

void	garbage_collector(t_garbage **garbage, t_shell *shell)
{
	ft_lstclear(garbage, free);
	free_shell(shell);
}