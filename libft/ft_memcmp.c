/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:31:26 by lbarlett          #+#    #+#             */
/*   Updated: 2023/10/11 14:32:32 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*temp_s1;
	unsigned char		*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (temp_s1[i] == temp_s2[i] && i < n - 1)
		i++;
	return (temp_s1[i] - temp_s2[i]);
}
/*
int main() {
    char buffer1[] = "Hello, World!";
    char buffer2[] = "Hello, Universe!";
    size_t n = 6; // Number of bytes to compare

    int result = memcmp(buffer1, buffer2, n);

    if (result < 0) {
        printf("Buffers are different for the first %zu bytes.\n", n);
    } else if (result > 0) {
        printf("Buffers are different for the first %zu bytes.\n", n);
    } else {
        printf("Buffers are equal for the first %zu bytes.\n", n);
    }

    return 0;
}*/
