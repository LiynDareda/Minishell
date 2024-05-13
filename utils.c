/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:01:22 by lbarlett          #+#    #+#             */
/*   Updated: 2024/04/24 12:02:03 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free (mat[i]);
		i++;
	}
	free (mat);
	return (0);
}

int	matlen(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

char	**env_copy(char **envp)
{
	int		i;
	int		j;
	char	**env_copy;

	i = 0;
	j = 0;
	env_copy = (char **)malloc(sizeof(char *) * (matlen(envp) + 1));
	while(envp[i])
	{
		j = 0;
		env_copy[i] = (char *)malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
		while (envp[i][j])
		{
			env_copy[i][j] = envp[i][j];
			j++;
		}
		env_copy[i][j] = '\0';
		i++;
	}
	env_copy[i] = NULL;
	return (env_copy);
}

size_t	ft_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int	check_last_dq(char *args)
{
	int	i;
	int dq;

	i = 0;
	while (args[i])
	{
		if(args[i] == '"')
			dq++;
		i++;
	}
	return (dq);
}

int	check_last_sq(char *args)
{
	int	i;
	int sq;

	i = 0;
	while (args[i])
	{
		if(args[i] == 34)
			sq++;
		i++;
	}
	return (sq);
}