/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:05:31 by lbarlett          #+#    #+#             */
/*   Updated: 2023/10/11 14:05:31 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;
	char	ch;

	ch = (char)c;
	tmp = (char *)s;
	i = ft_strlen(tmp);
	while (tmp[i] != ch && i > 0)
		i--;
	if (i == 0 && tmp[i] != ch)
		return (NULL);
	return (tmp + i);
}
/*
int main() {
    const char *str = "Hello, World!";
    int target = 'o';

    char *result = ft_strrchr(str, target);

    if (result) {
        printf("Character '%c' found at position: %ld\n", 
        				(char)target, result - str);
    } else {
        printf("Character '%c' not found in the string.\n", (char)target);
    }

    return 0;
}*/
