/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:02:56 by espinell          #+#    #+#             */
/*   Updated: 2024/05/06 13:30:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*valid_command(char **command, char **env)
{
	int		i;
	char	*tmp;
	char	*command2;

	i = 0;
	command2 = ft_strjoin("/", command[0]);
	while (env[i])
	{
		if (ft_strnstr(command2, "//bin", 5))
			tmp = ft_strjoin(env[i], command2 + 5);
		else
			tmp = ft_strjoin(env[i], command2);
		if (access(tmp, F_OK) == 0)
		{
			free(command2);
			return (tmp);
		}
		free (tmp);
		i++;
	}
	free(command2);
	return (NULL);
}

char	**get_env(char **envp)
{
	int		i;
	char	**mat;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			mat = ft_split(envp[i] + 5, ':');
			return (mat);
		}
		i++;
	}
	return (NULL);
}

char	*ft_readline(char *str, t_garbage *garbage, t_shell *shell)
{
	char	*line;

	line = readline(str);
	ft_lstadd_back(&garbage, ft_lstnew(line));
	if (!line)
	{
		printf("exit\n");
		garbage_collector(&garbage, shell);
		ft_exit(0);
	}
	return (line);
}

int	is_valid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

char	**check_cmdtab(char **shell)
{
	int		i;
	char	**cmdtab;

	i = 0;
	cmdtab = ft_split(shell, ';');
	return (cmdtab);
}