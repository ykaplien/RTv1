/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 21:57:17 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/25 10:37:59 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t len;
	size_t ind;
	size_t pos;

	len = 0;
	ind = 0;
	pos = 0;
	while (needle[len])
		len++;
	if (len == 0)
		return ((char *)haystack);
	while (haystack[ind])
	{
		while (needle[pos] == haystack[ind + pos])
		{
			if (pos == len - 1)
				return ((char *)haystack + ind);
			pos++;
		}
		pos = 0;
		ind++;
	}
	return (NULL);
}
