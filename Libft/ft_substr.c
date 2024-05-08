/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:55:20 by lbarlett          #+#    #+#             */
/*   Updated: 2023/10/17 16:55:20 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (start > ft_strlen((char *)s))
	{
		sub_s = (char *)malloc(sizeof(char) * 1);
		if (!sub_s)
			return (NULL);
		sub_s[0] = '\0';
		return (sub_s);
	}
	i = -1;
	s += start;
	if (ft_strlen((char *)s) <= len)
		sub_s = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	else
		sub_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_s)
		return (NULL);
	while (s[++i] != '\0' && i < len)
		sub_s[i] = s[i];
	sub_s[i] = '\0';
	return (sub_s);
}
/*
int main() {


    const char *original = "This is a test string.";
    unsigned int start = 5; // Start at position 5 (0-based index)
    size_t length = 7; // Length of the substring

    char *substring = ft_substr(original, start, length);

    if (substring) {
        printf("Original: %s\n", original);
        printf("Substring: %s\n", substring);
        free(substring); // Don't forget to free the allocated memory.
    } else {
        printf("Memory allocation failed or substring creation failed.\n");
    }
   
   	char	str[] = "lorem ipsum dolor sit amet";
	char	*strsub;
	int		arg;
	char *bullshit;
    if (!(strsub = ft_substr(str, 400, 20)))
        printf("%s\n", "NULL");
    else
    {
        bullshit = (char *)&strsub[30];
        bullshit = "FULL BULLSHIT";
        if (strsub)
            printf("%s\n", strsub);
        else
            printf("%s\n", "rip");
    }
    if (str == strsub)
        printf("%s\n", "\nA new string was not returned");
    (void)bullshit;

    return 0;
}*/
