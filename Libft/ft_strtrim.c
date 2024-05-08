/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:17:33 by lbarlett          #+#    #+#             */
/*   Updated: 2023/10/12 12:17:33 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen((char *)s1);
	if (s1[i] != '\0' && set[i] != '\0')
	{
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
	}
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)&s1[i], j - i + 1);
	str[j - i] = '\0';
	return (str);
}
/*
int main() {
    const char *original = "lorem ipsum dolor sit amet";
    const char *set = "tel"; // Set of characters to trim

    char *trimmed = ft_strtrim(original, set);

    if (trimmed) {
        printf("Original: \"%s\"\n", original);
        printf("Trimmed: \"%s\"\n", trimmed);
        free(trimmed); // Don't forget to free the allocated memory.
    } else {
        printf("Memory allocation failed or trimming failed.\n");
    }

    return 0;
}*/
