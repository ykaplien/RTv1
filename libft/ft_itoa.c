/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:39:36 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 20:53:55 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numsize(int n)
{
	int		size;

	size = 0;
	if (n <= 0)
	{
		size++;
	}
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		s_num;

	s_num = ft_numsize(n);
	res = (char *)malloc(sizeof(char) * (s_num + 1));
	if (!res)
		return (NULL);
	ft_bzero(res, ft_strlen(res) + 1);
	if (n == 0)
		return ("0");
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strcpy(res, "-2147483648"));
		n *= -1;
	}
	while (n)
	{
		res[--s_num] = n % 10 + 48;
		n = n / 10;
	}
	if (res[0] == 0)
		res[0] = '-';
	return (res);
}
