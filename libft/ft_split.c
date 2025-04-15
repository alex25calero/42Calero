/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:00:36 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/15 13:18:38 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char const *s, char limit)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != limit && (i == 0 || s[i - 1] == limit))
			words++;
		i++;
	}
	return (words);
}

size_t	count_letters(char const *s, char limit, size_t start)
{
	size_t	len;

	len = 0;
	while (s[start + len] && s[start + len] != limit)
		len++;
	return (len);
}

void	free_split(char **res, size_t j)
{
	while (j--)
		free(res[j]);
	free(res);
}

char	**fill_split(char const *s, char limit, char **res)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == limit)
			i++;
		if (s[i])
		{
			len = count_letters(s, limit, i);
			res[j] = malloc((len + 1) * sizeof(char));
			if (!res[j])
				return (free_split(res, j), NULL);
			k = 0;
			while (k < len)
				res[j][k++] = s[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char limit)
{
	size_t	words;
	char	**res;

	if (!s)
		return (NULL);
	words = count_words(s, limit);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (fill_split(s, limit, res));
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char *str = "Hola  mundo  cruel";
	char limit = ' ';
	char **words = ft_split(str, limit);

	if (!words)
	{
		printf("Error al dividir la cadena.\n");
		return (1);
	}
	for (int i = 0; words[i] != NULL; i++)
	{
		printf("Palabra %d: \"%s\"\n", i + 1, words[i]);
		free(words[i]);
	}
	free(words);
	return (0);
}
*/