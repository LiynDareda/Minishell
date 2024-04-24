/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:17:22 by lbarlett          #+#    #+#             */
/*   Updated: 2023/10/11 12:17:22 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] == s2[i] && i < n && s1[i] != '\0')
		i++;
	if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main() {
    const char *str1 = "abcdef";
    const char *str2 = "abc\375xx";
    size_t n = 5; // Number of characters to compare

    int result = ft_strncmp(str1, str2, n);

    if (result < 0) {
        printf("'%s' is less than '%s' for the first %zu characters.\n", 
        							str1, str2, n);
    } else if (result > 0) {
        printf("'%s' is greater than '%s' for the first %zu characters.\n", 
        							str1, str2, n);
    } else {
        printf("'%s' is equal to '%s' for the first %zu characters.\n", str1, 
        							str2, n);
    }

    return 0;
}*/
