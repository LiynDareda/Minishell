/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:38:47 by lbarlett          #+#    #+#             */
/*   Updated: 2024/04/24 12:00:20 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(int id)
{
	perror("Error");
	exit(id);
}

void	ft_exit(int id)
{
	write(2, "Error\n", 6);
	exit (id);
}
