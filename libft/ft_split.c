/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:56:59 by lbarlett          #+#    #+#             */
/*   Updated: 2023/10/17 16:58:09 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	*ft_matrix(char *s, char c, int *index)
{
	int		j;
	char	*word;
	int		i;

	i = *index;
	j = 0;
	while (s[i + j] != c && s[i + j] != '\0')
		j++;
	word = (char *)ft_calloc(j + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + i, j + 1);
	*index = i + j;
	return (word);
}

static void	*ft_free_matrix(char **s, int word)
{
	while (word >= 0)
	{
		free(s[word]);
		word--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strsp;
	int		nwords;
	int		i;
	int		word;

	nwords = ft_count_words((char *)s, (char)c);
	strsp = (char **)ft_calloc(nwords + 1, sizeof(char *));
	if (!strsp)
		return (NULL);
	word = -1;
	i = 0;
	while (++word < nwords)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			strsp[word] = ft_matrix((char *)s, c, &i);
			if (strsp[word] == NULL)
				return (ft_free_matrix(strsp, word));
		}
	}
	strsp[word] = NULL;
	return (strsp);
}
/*
int main() {
    char str[] = "Questo è un esempio di divisione;di;stringa; ";
    char delimiter = ' ';

    char **result = ft_split(str, delimiter);

    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("Parola %d: %s\n", i + 1, result[i]);
            free(result[i]);
        }

        free(result);
    } else {
        printf("Errore nell'allocazione di memoria.\n");
    }

    return 0;
}*/
