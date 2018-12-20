/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:59:23 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 21:37:01 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	len;
	size_t	len2;

	len = 0;
	len2 = 0;
	if (s)
	{
		len2 = ft_strlen(s) - 1;
		while (s[len] && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
			len++;
		if (s[len] == '\0')
			return ("\0");
		while (len2 > 0 && (s[len2] == ' ' || s[len2] == '\n'
							|| s[len2] == '\t'))
			len2--;
		res = (char *)malloc(sizeof(char) * (len2 - len + 2));
		if (res == NULL)
			return (NULL);
		res[len2 - len + 1] = '\0';
		ft_strncpy(res, &s[len], (len2 - len + 1));
		return (res);
	}
	return (NULL);
}
