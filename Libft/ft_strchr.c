/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:31:02 by lbarlett          #+#    #+#             */
/*   Updated: 2023/10/11 11:31:02 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
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
