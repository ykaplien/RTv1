/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 20:37:21 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 21:58:40 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *n, size_t len)
{
	size_t len_n;
	size_t ind;
	size_t pos;

	len_n = 0;
	ind = 0;
	pos = 0;
	while (n[len_n])
		len_n++;
	if (len_n == 0 || s == n)
		return ((char *)s);
	len--;
	while (s[ind] && len)
	{
		while (n[pos] == s[ind + pos] && len)
		{
			if (pos == len_n - 1)
				return ((char *)s + ind);
			pos++;
			len--;
		}
		pos = 0;
		ind++;
	}
	return (NULL);
}
