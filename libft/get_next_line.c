/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:53:27 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/16 12:54:03 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_parsing(const int fd, char **src)
{
	char			localbuf[BUFF_SIZE + 1];
	char			*tmp;
	int				i;

	if ((i = read(fd, localbuf, BUFF_SIZE)) > 0)
	{
		localbuf[i] = '\0';
		tmp = *src;
		*src = ft_strjoin(tmp, localbuf);
		free(tmp);
	}
	return (i);
}

static void	ft_norm(char **src, char *nl)
{
	char			*tmp;

	tmp = ft_strdup(nl + 1);
	ft_bzero(*src, ft_strlen(*src));
	ft_strcat(*src, tmp);
	free(tmp);
}

int			get_next_line(const int fd, char **line)
{
	static char		*src[4864];
	char			*nl;
	int				seted;

	if (fd < 0 || !line || fd >= 4864 || BUFF_SIZE < 1 || BUFF_SIZE > STACK_MAX)
		return (-1);
	if (src[fd] == NULL)
		src[fd] = ft_strnew(1);
	while (!(nl = ft_strchr(src[fd], '\n')))
	{
		if ((seted = ft_parsing(fd, &src[fd])) == -1)
			return (-1);
		if (!nl && seted == 0)
		{
			if (src[fd][0] == '\0')
				return (0);
			*line = src[fd];
			src[fd] = NULL;
			return (1);
		}
	}
	*line = ft_strsub(src[fd], 0, nl - src[fd]);
	ft_norm(&src[fd], nl);
	return (1);
}
