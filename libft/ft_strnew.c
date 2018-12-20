/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:45:39 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/27 21:04:10 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char *res;

	if (size > 9223372036854775807 || size == 0)
		return (0);
	res = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1));
	if (res == NULL)
		return (0);
	ft_bzero(res, size + 1);
	return ((char *)res);
}
