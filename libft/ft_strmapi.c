/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:41:01 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 21:20:17 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	ind;
	char	*res;

	ind = 0;
	if (s && *s)
	{
		res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (res == NULL)
			return (NULL);
		while (s[ind])
		{
			res[ind] = f((unsigned int)ind, s[ind]);
			ind++;
		}
		res[ind] = '\0';
		return (res);
	}
	return (NULL);
}
