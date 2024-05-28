/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:37:13 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/15 12:28:58 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_idchar(char *args, char c)
{
	t_index	id;

	id.i = 0;
	while (args[id.i])
	{
		if (args[id.i] == c)
			return (id.i);
		id.i++;
	}
	return (-1);
}

int	ft_var_update(char *args, char *envp)
{
	t_index	id;

	id.i = 0;
	id.k = 0;
	free(envp);
	envp = (char *)malloc(sizeof(char) * (ft_strlen(args) + 1));
	while (args[id.i])
	{
		if (args[id.k] == '\'' || args[id.k] == '\"')
			id.k++;
		envp[id.i] = args[id.k];
		id.i++;
		id.k++;
	}
	envp[id.i] = '\0';
	return (0);
}

void	add_env(char *str, char **envp, int i, int *j)
{
	int	k;

	k = 0;
	while (str[++*j])
	{
		if (str[k] == '\'' || str[k] == '\"')
			k++;
		envp[i][*j] = str[k++];
	}
}
