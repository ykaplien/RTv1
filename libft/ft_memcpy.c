/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:53:01 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/22 14:36:11 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_c;
	unsigned char *src_c;

	dst_c = (unsigned char*)dst;
	src_c = (unsigned char*)src;
	if (dst == src)
		return (dst);
	while (n--)
		*dst_c++ = *src_c++;
	return (dst);
}
