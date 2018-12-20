/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:34:14 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/22 18:13:48 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *res_point;

	res_point = (unsigned char *)b;
	if (len == 0)
		return (b);
	while (len--)
		*(res_point)++ = (unsigned char)c;
	return (b);
}
