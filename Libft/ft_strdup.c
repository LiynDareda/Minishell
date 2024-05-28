/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:51:20 by lbarlett          #+#    #+#             */
/*   Updated: 2023/10/11 15:51:20 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s, int apex)
{
	char	*dup;
	int		i;

	i = -1;
	dup = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!dup)
		return (NULL);
	if (apex == 1)
	{
		while (s[++i] != '\0' && s[i] != 34 && s[i] != 39)
			dup[i] = s[i];
		dup[i] = '\0';
	}
	else
	{
		while (s[++i] != ' ' && s[i] != '\0')
			dup[i] = s[i];
		dup[i] = '\0';
	}
	return (dup);
}

/*
int main() {
    const char *original = "Hello, World!";
    char *duplicate = ft_strdup(original);

    if (duplicate) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate); // Don't forget to free the allocated memory.
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}*/
