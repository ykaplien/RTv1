/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:06:02 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/25 13:53:26 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t index;

	index = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		if (((unsigned char *)src)[index] == (unsigned char)c)
			return ((unsigned char *)dst + index + 1);
		index++;
	}
	return (NULL);
}
