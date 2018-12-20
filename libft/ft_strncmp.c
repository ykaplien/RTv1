/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:00:30 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 21:21:46 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	ind;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ind = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (ss1[ind] == ss2[ind] && ss1[ind] != '\0' && ss2[ind] != '\0' && n--)
		ind++;
	return (ss1[ind] - ss2[ind]);
}
