/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:35:59 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/23 12:10:46 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_char(const char *s)
{
	int		i;
	char	flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (!flag && (s[i] == '"' || s[i] == '\''))
			flag = s[i];
		else if (flag && s[i] == flag)
			flag = 0;
		else if (!flag && s[i] == ' ')
			break ;
		i++;
	}
	return (i);
}

static int	count_words(const char *s)
{
	int		count;
	int		i;
	char	flag;

	count = 0;
	i = 0;
	flag = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && (flag || s[i] != ' '))
			{
				if (!flag && (s[i] == '"' || s[i] == '\''))
					flag = s[i];
				else if (flag && s[i] == flag)
					flag = 0;
				i++;
			}
		}
	}
	return (count);
}

static char	*extract_word(const char *s, int len)
{
	if ((s[0] == '"' || s[0] == '\'') && len >= 2 && s[len - 1] == s[0])
		return (ft_substr(s + 1, 0, len - 2));
	return (ft_substr(s, 0, len));
}

void	free_split(char **arr, int i)
{
	while (--i >= 0)
		free(arr[i]);
	free(arr);
}

char	**ft_split_cmd(const char *s)
{
	char	**res;
	int		words;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	words = count_words(s);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		while (*s == ' ')
			s++;
		len = count_char(s);
		res[i] = extract_word(s, len);
		if (!res[i])
			return (free_split(res, i), NULL);
		s += len;
		i++;
	}
	res[i] = NULL;
	return (res);
}
