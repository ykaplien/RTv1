/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:08:19 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 21:57:11 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		*ft_countalph(char const *s, char c, int words)
{
	int		*wordslen;
	int		counter;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	counter = 0;
	if (!s || !c || !words)
		return (0);
	wordslen = (int *)malloc(sizeof(int) * words);
	while (s[i[0]] && words)
	{
		if (s[i[0]] != c)
		{
			counter++;
			if (s[i[0] + 1] == c || !s[i[0] + 1])
			{
				wordslen[i[1]++] = counter + 1;
				counter = 0;
				words--;
			}
		}
		i[0]++;
	}
	return (wordslen);
}

static	int		ft_countwords(char const *s, char c)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

static	void	ft_fillarr(char const *s, char c, char **arr)
{
	int		i;
	int		i_words;
	int		i_alph;

	i = 0;
	i_words = 0;
	i_alph = 0;
	if (!s || !c || !arr)
		return ;
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[i_words][i_alph++] = s[i];
			if (!s[i + 1] || s[i + 1] == c)
			{
				arr[i_words][i_alph] = '\0';
				i_alph = 0;
				i_words++;
			}
		}
		i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i_words;
	int		*wordslen;

	i_words = 0;
	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	wordslen = ft_countalph(s, c, words);
	if (!(arr = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (i_words < words)
	{
		if (!(arr[i_words] = (char *)malloc(sizeof(char) * wordslen[i_words])))
			return (NULL);
		i_words++;
	}
	ft_fillarr(s, c, arr);
	arr[i_words] = NULL;
	free(wordslen);
	return (arr);
}
