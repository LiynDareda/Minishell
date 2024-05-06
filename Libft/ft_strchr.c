/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:31:02 by lbarlett          #+#    #+#             */
/*   Updated: 2024/05/06 13:23:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (0);
		s++;
	}
	if ((char)c == '\0')
		return (0);
	return (1);
}
/*
int main() {
    const char *str = "Hello, World!";
    int target = 'o' + 256;

    char *result = ft_strchr(str, target);

    if (result) {
        printf("Character '%c' found at position: %ld\n", 
        					(char)target, result - str);
    } else {
        printf("Character '%c' not found in the string.\n", (char)target);
    }

    return 0;
}*/