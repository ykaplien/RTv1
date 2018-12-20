/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:03:54 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 20:54:57 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*src1;
	unsigned char	*src2;

	index = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (index < n)
	{
		if (src1[index] != src2[index])
			return (src1[index] - src2[index]);
		index++;
	}
	return (0);
}
