/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:16:03 by espinell          #+#    #+#             */
/*   Updated: 2024/05/09 12:16:03 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_idchar(char *args, char c)
{
    t_index id;

    id.i = 0;
    while (args[id.i] )
    {
        if (args[id.i] == c)
            return (id.i);
        id.i++;
    }
    return(-1);
}

void    ft_var_update(char *args, char *envp)
{
    t_index id;

    id.i = 0;
    id.k = 0;
    free(envp);
    envp = (char *)malloc(sizeof(char) * (ft_strlen(args) + 1));
    while (args[id.i])
    {
        envp[id.i] = args[id.k];
        id.i++;
        id.k++;
    }
    envp[id.i] = '\0';
}

char *ft_check_var_export(char *str, int i, t_shell *shell)
{
    int start;
    int len;
    char *var_name;
    char *res;

	len = 0;
	start = i;
	res = NULL;
    while (str[i] && str[i] != ' ' && str[i] != 39 && str[i] != 34 &&  str[i] != '$')
    {
        len++;
        i++;
    }
    var_name = malloc(sizeof(char) * (len + 1));
    if (!var_name)
        return (NULL);
    strncpy(var_name, str + start, len);
    var_name[len] = '\0';
    i = 0;
    while (shell->env[i])
    {
        if (strncmp(shell->env[i], var_name, len) == 0 && shell->env[i][len] == '=')
        {
            res = strdup(shell->env[i] + len + 1);
            break ;
        }
        i++;
    }
    free(var_name);
    return (res);
}

int	ft_strncmp_export(const char *s1, char *s2, int n, t_shell *shell)
{
    t_index id;
	char *str;

    id.i = 0;
    id.j = 0;
    while (s2[id.i])
    {
		if (s2[id.i + 1] == '$')
	    {
			str = ft_strnjoin(s2, ft_check_var_export(s2, id.i + 1, shell), id.i);
	    }
		id.i++;
    }
	if(!str)
		str = ft_strdup(s2);
	if (n <= 0)
		return (1);
	while (s1[id.i] == str[id.i] && id.i < n && str[id.i] != '\0')
		id.i++;
	if (id.i == n)
		return ((unsigned char)s1[id.i - 1] - (unsigned char)str[id.i - 1]);
	else
		return ((unsigned char)s1[id.i] - (unsigned char)str[id.i]);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*joined;
	int		i;
	int		j;

	joined = (char *)malloc(sizeof(char) * (n + ft_strlen((char *)s2) + 1));
	i = 0;
	j = 0;
	if (!joined)
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		joined[i] = s2[j];
		i++;
		j++;
	}
	joined[i] = '\0';
	return (joined);
}