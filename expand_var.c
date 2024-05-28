/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:58:11 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/27 13:50:35 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int ft_lenvar(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			while (str[i] && str[i] != ' ' && str[i] != 39 && str[i] != 34)
			{
				i++;
				len++;
			}
		}
		i++;
	}
	return (len);
}

static char	*ft_substitute(char *str1, char *str2)
{
	char	*res;
	t_index	id;

	id.i = 0;
	id.j = 0;
	id.k = 0;	
	res = malloc(sizeof(char) *
		(ft_strlen(str1) + ft_strlen(str2) + 1 - ft_lenvar(str1)));
	if (!res)
		return (NULL);
	while (str1[id.j])
	{
		if (str1[id.j] == '$')
		{
			while (str2[id.k])
				res[id.i++] = str2[id.k++];
			id.j += ft_lenvar(str1);
		}
		else
			res[id.i++] = str1[id.j++];
	}
	res[id.i] = '\0';
	free(str1);
	free(str2);
	return (res);
}

void	expand_var(char **cmd, t_shell *shell)
{
	t_index	id;

	id.i = 0;
	while (cmd[id.i])
	{
		id.j = 0;
		while (cmd[id.i][id.j])
		{
			if (cmd[id.i][id.j] == '$')
			{
				if (ft_check_var(cmd[id.i], ++id.j, shell))
					shell->cmdtab[id.i] = ft_substitute(shell->cmdtab[id.i], ft_check_var(cmd[id.i], id.j, shell));
				printf("%s\n", shell->cmdtab[id.i]);
			}
			id.j++;
		}
		id.i++;
	}
}
