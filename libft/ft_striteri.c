/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:05:54 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/28 11:10:07 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t ind;

	ind = 0;
	if (s && *s)
	{
		while (s[ind])
		{
			f((unsigned int)ind, &s[ind]);
			ind++;
		}
	}
}
