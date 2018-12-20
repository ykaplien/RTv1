/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:31:17 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 22:02:00 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ind;
	size_t	ind2;
	char	*res;
	size_t	len;

	ind = 0;
	ind2 = 0;
	if (s2 && s1)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		res = (char *)malloc(sizeof(char) * (len + 1));
		if (!res)
			return (0);
		while (s1[ind])
		{
			res[ind] = s1[ind];
			ind++;
		}
		while (s2[ind2])
			res[ind++] = s2[ind2++];
		res[ind] = '\0';
		return (res);
	}
	return (0);
}
