/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddulgher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:32:40 by ddulgher          #+#    #+#             */
/*   Updated: 2017/02/07 17:08:05 by ddulgher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
			s++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		nr_words;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	nr_words = ft_count_words(s, c);
	words = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1));
	if (words == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			words[i] = ft_strnew(ft_word_len(s, c));
			ft_strncpy(words[i], s, ft_word_len(s, c));
			s = s + ft_word_len(s, c);
			i++;
		}
		else
			s++;
	}
	words[i] = 0;
	return (words);
}
