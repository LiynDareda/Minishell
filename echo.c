/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:30:29 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/27 12:30:06 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_len(char *str, int i)
{
	int	start;

	start = i;
	while (str[i] && str[i] != ' ' && str[i] != 39 && str[i] != 34
		&& str[i] != '$')
		i++;
	return (i - start);
}

static char *ft_strncpy(char *dest, const char *src, int n)
{
	int i;

	i = 0;
    while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_check_var(char *str, int i, t_shell *shell)
{
	int		start;
	int		len;
	char	*var;
	char	*res;

	len = get_len(str, i);
	start = i;
	res = NULL;
	var = malloc(sizeof(char) * (len + 1));
	if (!var)
		return (NULL);
	ft_strncpy(var, str + start, len);
	var[len] = '\0';
	i = -1;
	while (shell->env[++i])
	{
		if (ft_strncmp(shell->env[i], var, len) == 0 && shell->env[i][len] == '=')
		{
			res = ft_strdup(shell->env[i] + len + 1, 0);
			break ;
		}
	}
	free(var);
	return (res);
}

static void	process_variable(char *args, t_shell *shell, int *i, int fd)
{
	char	*var;
	char	*res;

	if (args[++*i] == '?')
	{
		(*i)++;
		ft_putnbr_fd(g_exit_sig, fd);
		return ;
	}
	if (!(ft_isalpha(args[*i]) || args[*i] == '_'))
	{
		(*i)++;
		return ;
	}
	res = ft_calloc((strlen(args) - *i + 1), sizeof(char));
	while (ft_isalnum(args[*i]) || args[*i] == '_')
	{
		var = ft_check_var(args, *i, shell);
		if (var)
			res = ft_strjoin(res, var);
		free(var);
		(*i) += get_len(args, *i);
	}
	ft_putstr(res);
	free(res);
}

int	ft_echo(char **args, t_shell *shell, int flag, int fd)
{
	t_echo	e;

	e.j = 0;
	e.i = 0;
	e.apex = 0;
	change_snake_to_space(shell->cmd->scmd->args);
	while (args[++e.j])
	{
		e.i = 0;
		while (args[e.j][e.i])
		{
			if (e.apex == 0 && (args[e.j][e.i] == 34 || args[e.j][e.i] == 39))
				e.apex = args[e.j][e.i++];
			else if ((args[e.j][e.i] == 34 || args[e.j][e.i] == 39)
				&& e.apex == args[e.j][e.i])
			{
				e.apex = 0;
				e.i++;
			}
			else if ((e.apex == 34 || e.apex == 0) && args[e.j][e.i] == '$')
				process_variable(args[e.j], shell, &e.i, fd);
			else
				ft_putchar_fd(args[e.j][e.i++], fd);
		}
		if (args[e.j + 1])
			ft_putchar_fd(' ', fd);
	}
	if (!flag)
		ft_putchar_fd('\n', fd);
	return (0);
}
