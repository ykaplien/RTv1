/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:10:33 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 21:19:47 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			res[ind] = f(s[ind]);
			ind++;
		}
		res[ind] = '\0';
		return (res);
	}
	return (NULL);
}
