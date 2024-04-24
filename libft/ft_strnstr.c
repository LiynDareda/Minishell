/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:56:53 by lbarlett          #+#    #+#             */
/*   Updated: 2023/10/11 14:58:06 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (little[i] == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && big[i + j] != '\0'
				&& (j + i) < len)
				j++;
			if (ft_strlen((char *)little) == j)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*
int main() {
    const char *haystack = "lorem ipsum dolor sit amet";
    const char *needle = "dolor";
    size_t len = strlen(haystack);

    char *result = ft_strnstr(haystack, needle, 15);

    if (result) {
        printf("'%s' found in '%s' at position: %ld\n", needle, haystack, 
														result - haystack);
    } else {
        printf("'%s' not found in '%s'\n", needle, haystack);
    }

    return 0;
}*/
