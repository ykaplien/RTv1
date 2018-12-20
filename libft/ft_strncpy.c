/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:18:42 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/23 15:44:16 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t ind;

	ind = 0;
	while (src[ind] != '\0' && len > ind)
	{
		dst[ind] = src[ind];
		ind++;
	}
	while (len > ind)
	{
		dst[ind] = '\0';
		ind++;
	}
	return (dst);
}
