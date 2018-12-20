/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:09:16 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/28 14:28:39 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	if (!s || !*s)
		return (0);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (0);
	ft_strncpy(res, &s[start], len);
	res[len] = '\0';
	return (res);
}
