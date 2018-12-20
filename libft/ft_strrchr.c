/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:21:50 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 21:24:27 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		to_f;
	const char	*res;

	res = s;
	to_f = (char)c;
	while (*s++)
	{
		if (*s == to_f)
			res = s;
	}
	if (*res == to_f)
		return ((char *)res);
	else
		return (NULL);
}
