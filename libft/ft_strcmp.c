/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:25:14 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 21:16:18 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	ind;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ind = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (ss1[ind] == ss2[ind] && ss1[ind] != '\0' && ss2[ind] != '\0')
		ind++;
	return (ss1[ind] - ss2[ind]);
}
