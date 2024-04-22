/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:13:35 by espinell          #+#    #+#             */
/*   Updated: 2024/04/18 13:37:48 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>


typedef struct s_simplecmd
{
	char	*path; 
	char	**args;
}			t_simplecmd;

typedef struct s_cmd
{
	t_simplecmd		simplecmd[255];
	char			io[2][255];
}			t_cmd;

typedef struct minishell
{
	t_cmd	*cmd;
	char	*line;
	char	**env;
	char 	*token;
	char	**cmdtab;	
}			t_minishell;

typedef struct index
{
	int		i;
	int		j;
	int		k;
}			t_index;
