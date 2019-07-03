/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		parse_angle(t_rtv *rtv, double *angle)
{
	char		*string;
	double		temporary;

	temporary = 0.0;
	if (get_next_line(rtv->fd, &string) > 0)
	{
		if (ft_strncmp(string, "-angle:", 7) == 0)
		{
			if (is_num(ft_strchr(string, ':') + 1))
			{
				return (parse_angle_add(string, temporary, angle));
			}
		}
	}
	return (0);
}

int		parse_angle_add(char *string, double temporary, double *angle)
{
	temporary = (double)ft_atoi(&string[7]);
	free(string);
	if (temporary <= 0 || temporary > 360)
		return (0);
	*angle = tan(temporary / 2);
	return (1);	
}

int		parse_normal(t_rtv *rtv, t_vector *dest)
{
	char		**string2;
	char		*string;

	if ((get_next_line(rtv->fd, &string) > 0) &&
		(ft_strncmp(string, "-normal:", 8) == 0))
	{
		string2 = ft_strsplit(&string[8], ',');
		free(string);
		if (is_num(string2[0]))
		{
			if (is_num(string2[1]))
			{
				if (is_num(string2[2]))
				{
					if (!(string2[3]))
					{
						parse_normal_add(dest, string2);
						parse_normal_free(string2);
						return (1);
					}
				}
			}
		}
	}
	return (0);
}

void	parse_normal_add(t_vector *dest, char **string2)
{
	dest->y = (double)ft_atoi(string2[1]);
	dest->z = (double)ft_atoi(string2[2]);
	dest->x = (double)ft_atoi(string2[0]);
}

void	parse_normal_free(char **string2)
{
	free(string2[3]);
	free(string2[2]);
	free(string2[1]);
	free(string2);
	free(*string2);	
}