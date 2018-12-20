/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:02:48 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 21:17:00 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	ind;
	size_t	len;
	char	*str;

	ind = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s1[ind] != '\0')
	{
		str[ind] = s1[ind];
		ind++;
	}
	str[ind] = '\0';
	return (str);
}
