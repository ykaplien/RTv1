/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		parse_plane(t_rtv *rtv)
{
	t_plane		dest;
	t_list		*temporary;

	temporary = NULL;
	if (parse_color(rtv, &(dest.color)))
	{
		if (parse_reflect(rtv, &(dest.reflect)))
		{
			if (parse_normal(rtv, &(dest.vector)))
			{
				if (parse_center(rtv, &(dest.center)))
				{
					parse_plane_add(temporary, dest, rtv);
					return (1);
				}
			}
		}
	}
	parse_plane_error();
	return (0);
}

void	parse_plane_add(t_list *temporary, t_plane plane, t_rtv *rtv)
{
	temporary = ft_lstnew(&(plane), sizeof(t_plane));
	temporary->content_size = 440;
	ft_lstadd(&(rtv->obj), temporary);
}

void	parse_plane_error(void)
{
	ft_putendl("INCORRECT PLANE INFO");
}

int		parse_cylinder(t_rtv *rtv)
{
	t_cylinder	dest;
	t_list		*temporary;

	temporary = NULL;
	if (parse_color(rtv, &(dest.color)))
	{
		if (parse_reflect(rtv, &(dest.reflect)))
		{
			if (parse_radius(rtv, &(dest.radius)))
			{
				if (parse_normal(rtv, &(dest.vector)))
				{
					if (parse_center(rtv, &(dest.center)))
					{
						parse_cylinder_add(temporary, dest, rtv);
						return (1);
					}
				}
			}
		}
	}
	parse_cylinder_error();
	return (0);
}

void	parse_cylinder_add(t_list *temporary, t_cylinder dest, t_rtv *rtv)
{
	temporary = ft_lstnew(&(dest), sizeof(t_cylinder));
	temporary->content_size = 442;
	ft_lstadd(&(rtv->obj), temporary);
}
