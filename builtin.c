/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:15:44 by espinell          #+#    #+#             */
/*   Updated: 2024/05/09 12:15:44 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    export(char *args, char **envp)
{
    t_index id;

    id.i = 0;
    id.j = 0;
    id.k = 0;
	if (args == NULL)
	{
		while (envp[id.i])
		{
			printf("declare -x %s\n", envp[id.i]);
			id.i++;
		}
		return ;
	}
    if ((args[0] >= 'a' && args[0] <= 'z') || (args[0] >= 'A' && args[0] <= 'Z') || args[0] == '$')
    {
        while (envp[id.i])
        {
            if (ft_strncmp_export(envp[id.i], args, ft_name(args)) == 0)
            {
                ft_var_update(args, envp[id.i]);
                return ;
            }
            id.i++;
        }
        envp[id.i] = (char *)malloc(sizeof(char) * (ft_strlen(args) + 1));
        while (args[id.j])
        {
            envp[id.i][id.j] = args[id.k];
            id.j++;
            id.k++;
        }
        envp[id.i][id.j] = '\0';
        id.i++;
        envp[id.i] = NULL;
    }
    else
        printf("export: `%s': not a valid identifier\n", args);
}

void    print_env(char **envp)
{
    t_index id;

    id.i = 0;
    while (envp[id.i])
    {
		if (ft_strchr(envp[id.i], '=') == 0)
        	printf("%s\n", envp[id.i]);
        id.i++;
    }
}

void    ft_quit(t_shell *shell, t_garbage **garbage, int signal)
{
    garbage_collector(garbage, shell);
    exit(signal);
}

void    pwd(char **envp)
{
    int i;

    i = 0;
    while(envp[i])
    {
        if (ft_strncmp(envp[i], "PWD", 3) == 0)
            printf("%s\n", envp[i] + 4);
        i++;
    }
}

void	unset(char *args, char **envp)
{
	int i;

	i = 0;
	while(envp[i])
	{
		if(ft_strncmp(envp[i], args, ft_strlen(args)) == 0)
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
}

