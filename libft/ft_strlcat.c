/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:00:46 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/25 18:23:21 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_i;
	size_t src_i;

	dst_i = 0;
	src_i = 0;
	if (dstsize == 0)
		return (dst_i + ft_strlen((char *)src));
	while (dst[dst_i] != '\0' && dst_i < dstsize)
		dst_i++;
	while (dstsize - 1 > dst_i + src_i && src[src_i])
	{
		dst[dst_i + src_i] = src[src_i];
		src_i++;
	}
	if (src_i)
		dst[dst_i + src_i] = '\0';
	return (ft_strlen((char *)src) + dst_i);
}
