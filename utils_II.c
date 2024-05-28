/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:35:19 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/15 15:46:13 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_and_free(pid_t pid, int **pfd, int i)
{
	waitpid(pid, NULL, 0);
	free_pfd(pfd, i);
}

int	free_pfd(int **pfd, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		free (pfd[i]);
		i++;
	}
	free (pfd);
	return (0);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
