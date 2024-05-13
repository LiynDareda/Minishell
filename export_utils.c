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