/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:30:08 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/24 18:17:29 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char to_f;

	to_f = (char)c;
	if (to_f == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (s && *s)
	{
		if (*s == to_f)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
