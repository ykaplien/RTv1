/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		parse_reflect(t_rtv *rtv, double *rofl)
{
	double	temporary;
	char	*string1;
	char	*string;

	if (get_next_line(rtv->fd, &string) > 0)
	{
		if (ft_strncmp(string, "-specular:", 10) == 0)
		{
			string1 = ft_strchr(string, ':') + 1;
			if (is_num(string1))
			{
				temporary = (double)ft_atoi(&string[10]);
				free(string);
				return (parse_reflect_add(temporary, rofl));
			}
		}
	}
	return (0);
}

int		parse_reflect_add(double temporary, double *rofl)
{
	if (temporary >= 0 && temporary <= 999)
		*rofl = temporary;
	else if (temporary < 0)
		return (0);
	else
		*rofl = 1000;
	return (1);
}

int		parse_radius(t_rtv *rtv, double *dest)
{
	double	temporary;
	char	*string1;
	char	*string;

	if (get_next_line(rtv->fd, &string) > 0)
	{
		if (ft_strncmp(string, "-radius:", 8) == 0)
		{
			string1 = ft_strchr(string, ':') + 1;
			if (is_num(string1))
			{
				temporary = (double)ft_atoi(&string[8]);
				free(string);
				return (parse_radius_add(temporary, dest));
			}
		}
	}
	return (0);
}

int		parse_radius_add(double temporary, double *dest)
{
	if (temporary < 0)
		return (0);
	else
		*dest = temporary;
	return (1);
}

int		parse_center(t_rtv *rtv, t_vector *destenation)
{
	char	**string1;
	char	*string;

	if (get_next_line(rtv->fd, &string) > 0)
	{
		if (ft_strncmp(string, "-center:", 8) == 0)
		{
			string1 = ft_strsplit(&string[8], ',');
			parse_center_add(string1, destenation, string);
			parse_center_free(string1);
			return (1);
		}
	}
	return (0);
}
