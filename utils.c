/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:35:11 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/15 12:36:15 by mdella-r         ###   ########.fr       */
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
	while (envp[i])
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
