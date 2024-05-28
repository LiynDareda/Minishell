/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:28:22 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/27 12:46:00 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export(char *str, char **envp)
{
	t_index	id;

	id.i = -1;
	id.j = -1;
	if (str == NULL)
	{
		while (envp[++id.i])
			printf("declare -x %s\n", envp[id.i]);
		return (0);
	}
	if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
	{
		while (envp[++id.i])
			if (ft_strncmp(envp[id.i], str, ft_name(str)) == 0)
				return (ft_var_update(str, envp[id.i]));
		envp[id.i] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		add_env(str, envp, id.i, &id.j);
		envp[id.i][id.j] = '\0';
		envp[++id.i] = NULL;
	}
	else
		printf ("export: `%s': not a valid identifier\n", str);
	return (0);
}

int	print_env(char **envp, int fd)
{
	t_index	id;

	id.i = -1;
	id.j = -1;
	while (envp[++id.i])
	{
		if (ft_strchr(envp[id.i], '=') == 0)
		{
			ft_putstr(envp[id.i]);	
			ft_putchar_fd('\n', fd);
		}
	}
	return (0);
}


int	pwd(char **envp, int fd)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PWD", 3) == 0)
		{
			ft_putstr(envp[i] + 4);
			ft_putchar_fd('\n', fd);
		}
		i++;
	}
	return (0);
}

int	unset(char *args, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], args, ft_strlen(args)) == 0)
		{
			free(envp[i]);
			break ;
		}
		i++;
	}
	while (envp[i])
	{
		envp[i] = envp[i + 1];
		i++;
	}
	return (0);
}
