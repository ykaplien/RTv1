/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	parse_rotation(t_rtv *rtv, char *string)
{
	char	**temporary;
	int		error;

	error = 0;
	temporary = ft_strsplit(&string[9], ',');
	if (is_num(temporary[0]))
	{
		if (is_num(temporary[1]))
		{
			if (is_num(temporary[2]))
			{
				if (temporary[3] == NULL)
					parse_rotation_add(rtv, temporary);
				else
					parse_rotation_error(rtv);
			}
			else
				parse_rotation_error(rtv);
		}
		else
			parse_rotation_error(rtv);
	}
	else
		parse_rotation_error(rtv);
	parse_rotation_free(temporary);
}

void	parse_rotation_add(t_rtv *rtv, char **temporary)
{
	rtv->angels.x = (double)ft_atoi(temporary[0]);
	rtv->angels.y = (double)ft_atoi(temporary[1]);
	rtv->angels.z = (double)ft_atoi(temporary[2]);
}

void	parse_rotation_free(char **temporary)
{
	int		i;

	i = 1;
	free(temporary[1]);
	free(temporary[2]);
	while (i < 99)
		i++;
	free(temporary);
	free(*temporary);	
}

void	parse_rotation_error(t_rtv *rtv)
{
		ft_putendl("Incorrect info for ROTATION");
		rtv->angels = vector_add(0, 0, 0, 0);
}

int		parse_sphere(t_rtv *rtv)
{
	t_sphere	new_sphere;
	t_list		*temporary;

	temporary = NULL;
	if (parse_color(rtv, &(new_sphere.color)))
	{
		if (parse_reflect(rtv, &(new_sphere.reflect)))
		{
			if (parse_radius(rtv, &(new_sphere.radius)))
			{
				if (parse_center(rtv, &(new_sphere.center)))
				{
					parse_sphere_add(temporary, new_sphere, rtv);
					return (1);
				}
			}
		}
	}
	parse_sphere_error();
	return (0);
}
