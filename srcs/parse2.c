/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		parse_intense(t_rtv *rtv, double *intense)
{
	double		temporary;
	char		*string;
	char		*stringg;

	if (get_next_line(rtv->fd, &string) > 0)
	{
		if (ft_strncmp(string, "-intense:", 9) == 0)
		{
			stringg = ft_strchr(string, ':') + 1;
			if (is_num(stringg))
			{
				temporary = (double)ft_atoi(&string[9]);
				free(string);
				return (parse_intense_add(temporary, intense));
			}
		}
	}
	return (0);
}

int		parse_intense_add(double temporary, double *intense)
{
	if (temporary >= 0)
	{
		if (temporary <= 10)
			*intense = temporary / 10;
	}
	else if (temporary < 0)
		return (0);
	else
		*intense = 1;
	return (1);
}

int		parse_pos(t_rtv *rtv, t_vector *position)
{
	char		*line;
	char		**buffer;

	if (get_next_line(rtv->fd, &line) > 0)
	{
		if (ft_strncmp(line, "-position:", 10) == 0)
		{
			buffer = ft_strsplit(&line[10], ',');
			free(line);
			if (parse_pos_add_add(buffer))
			{
				parse_pos_add(buffer, position);
				parse_pos_free(buffer);
				return (1);
			}
		}
	}
	return (0);
}

void	parse_pos_add(char **buffer, t_vector *position)
{
	position->x = (double)ft_atoi(buffer[0]);
	position->y = (double)ft_atoi(buffer[1]);
	position->z = (double)ft_atoi(buffer[2]);
}

void	parse_pos_free(char **buffer)
{
	free(buffer[1]);
	free(buffer[2]);
	free(*buffer);
	free(buffer);	
}

int		parse_pos_add_add(char **buffer)
{
	if (is_num(buffer[0]))
	{
		if (is_num(buffer[1]))
		{
			if (is_num(buffer[2]))
			{
				if (buffer[3] == NULL)
				{
					return (1);
				}
			}
		}
	}
	return (0);
}