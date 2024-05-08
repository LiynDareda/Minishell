/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:29:12 by lbarlett          #+#    #+#             */
/*   Updated: 2023/10/12 11:29:12 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;

	joined = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	i = 0;
	j = 0;
	if (!joined)
		return (NULL);
	while (s1[i] != '\0')
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
/*
int main() {
    const char *str1 = "Hello, ";
    const char *str2 = "World!";
    
    char *result = ft_strjoin(str1, str2);

    if (result) {
        printf("Concatenated string: %s\n", result);
        free(result); // Don't forget to free the allocated memory.
    } else {
        printf("Memory allocation failed or concatenation failed.\n");
    }

    return 0;
}*/
