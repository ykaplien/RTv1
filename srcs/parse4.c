/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	parse_sphere_add(t_list *temporary, t_sphere new_sphere, t_rtv *rtv)
{
	temporary = ft_lstnew(&new_sphere, sizeof(t_sphere));
	temporary->content_size = 441;
	ft_lstadd(&(rtv->obj), temporary);
}

void	parse_sphere_error(void)
{
	ft_putendl("Incorrect info for CONE");
}

int		parse_color_add(char **temporary)
{
	t_vector	color;

	color.x = (double)ft_atoi(temporary[0]);
	color.y = (double)ft_atoi(temporary[1]);
	color.z = (double)ft_atoi(temporary[2]);
	return (rgb_to_hex(color));
}

void	parse_color_free(char **temporary)
{
	free(temporary[1]);
	free(temporary[2]);
	free(temporary);
	free(*temporary);
}

int		parse_color(t_rtv *rtv, int *color)
{
	char		*string;
	char		**temporary;

	if (get_next_line(rtv->fd, &string) > 0)
	{
		if (ft_strncmp(string, "-color:", 7) == 0)
		{
			temporary = ft_strsplit(&string[7], ',');
			free(string);
			if (is_num(temporary[0]))
			{
				if (is_num(temporary[1]))
				{
					if (is_num(temporary[2]) && temporary[3] == NULL)
					{
						*color = parse_color_add(temporary);
						parse_color_free(temporary);
						return (1);
					}
				}
			}
		}
	}
	return (0);
}
