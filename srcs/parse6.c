/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	parse_center_add(char **string1, t_vector *destenation, char *s)
{
	free(s);
	destenation->x = (double)ft_atoi(string1[0]);
	destenation->y = (double)ft_atoi(string1[1]);
	destenation->z = (double)ft_atoi(string1[2]);
}

void	parse_center_free(char **string1)
{
	free(string1[1]);
	free(string1[2]);
	free(string1);
	free(*string1);
}

void	parse_cone_add(t_list *temporary, t_cone new_cone, t_rtv *rtv)
{
	temporary = ft_lstnew(&new_cone, sizeof(t_cone));
	temporary->content_size = 443;
	ft_lstadd(&(rtv->obj), temporary);
}

int		parse_cone(t_rtv *rtv)
{
	t_cone		new_cone;
	t_list		*temporary;

	temporary = NULL;
	if (parse_color(rtv, &(new_cone.color)))
	{
		if (parse_reflect(rtv, &(new_cone.reflect)))
		{
			if (parse_angle(rtv, &(new_cone.angle)))
			{
				if (parse_normal(rtv, &(new_cone.vector)))
				{
					if (parse_center(rtv, &(new_cone.center)))
					{
						parse_cone_add(temporary, new_cone, rtv);
						return (1);
					}
				}
			}
		}
	}
	parse_cone_error();
	return (0);
}

void	parse_cone_error(void)
{
	ft_putendl("Incorrect info for CONE!!!");
}
