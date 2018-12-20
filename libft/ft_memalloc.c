/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:04:16 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/27 20:29:03 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *res;

	if (size > 9223372036854775807 || size == 0)
		return (0);
	res = (void *)malloc(sizeof(void) * size);
	if (res == NULL)
		return (0);
	ft_bzero(res, size);
	return ((void *)res);
}
