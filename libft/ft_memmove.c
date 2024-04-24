/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:21:59 by lbarlett          #+#    #+#             */
/*   Updated: 2023/10/11 14:18:53 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*temp_dest;
	char		*temp_src;

	i = 0;
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n-- > 0)
			temp_dest[n] = temp_src[n];
	}
	else
	{
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (dest);
}
/*
int main() {
    char *str1 = "lorem ipsum dolor sit amet";
    char *str2;
    str2 = str1 + 1;

    printf("Original str1: \"%s\"\n", str1);
    printf("Original str2: \"%s\"\n", str2);

    // Copy str1 to str2 using ft_memmove
    ft_memmove(str2, str1, 8);

    printf("After ft_memmove: str2 is \"%s\"\n", str2);

    return 0;
}*/
