/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:45:41 by lbarlett          #+#    #+#             */
/*   Updated: 2024/05/27 14:35:42 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c(int sig)
{
	g_exit_sig = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ctrl_d(int sig)
{
	g_exit_sig = 0;
	write(1, "exit\n", 5);
	exit(0);
}
void	ctrl_bslash(int sig)
{
	g_exit_sig = sig;
	//garbage_collector();
	write(1, "Quit (core dumped)\n", 19);
	exit(g_exit_sig);
}