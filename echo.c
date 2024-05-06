/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:22:45 by espinell          #+#    #+#             */
/*   Updated: 2024/05/02 14:36:41 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static char	*var_copy(char *env, char *var_name)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (env[i] != '=')
		i++;
	i++;
	res = malloc(sizeof(char) * ft_strlen(env) - i + 1);
	while (env[i])
	{
		res[j] = env[i];
		i++;
		j++;
	}
	return (res);
}*/

static char *ft_check_var(char *str, int i, t_shell *shell)
{
    int start = i;
    int len = 0;
    char *var_name, *res = NULL;

    while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
    {
        len++;
        i++;
    }

    var_name = malloc(sizeof(char) * (len + 1));
    if (!var_name)
        return NULL;
    strncpy(var_name, str + start, len);
    var_name[len] = '\0';

    i = 0;
    while (shell->env[i])
    {
        if (strncmp(shell->env[i], var_name, len) == 0 && shell->env[i][len] == '=')
        {
            res = strdup(shell->env[i] + len + 1);
            break;
        }
        i++;
    }
    free(var_name);
    return res;
}

static void process_variable(char **args, t_shell *shell, int *i, int fd)
{
    (*i)++;
    char *var = ft_check_var(*args, *i, shell);
    while ((*args)[*i] && (*args)[*i] != ' ')
        (*i)++;
    ft_putstr_fd(var, fd);
}

void ft_echo(char *args, t_shell *shell) 
{
	t_echo e;
	int fd;

	e.i = 5;
	e.flag = 0;
	fd = 1;
	e.apex = 0;
    if (ft_strncmp(args + e.i, "-n", 2) == 0)
        e.flag = 1;
	if (ft_strncmp(args + e.i, "-n", 2) == 0)
        e.i += 3;
    while (args[e.i])
	{
        if (e.apex == 0 && (args[e.i] == 34 || args[e.i] == 39))
            e.apex = args[e.i++];
        else if (e.apex == args[e.i] && (args[e.i] == 34 || args[e.i] == 39))
		{
            e.apex = 0;
			e.i++;
		}
        else if (e.apex == 34 && args[e.i] == '$')
            process_variable(&args, shell, &e.i, fd);
        else
            ft_putchar_fd(args[e.i++], fd);
    }
    if (!e.flag)
        ft_putchar_fd('\n', fd);
}