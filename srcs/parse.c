/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	parse_cam(t_rtv *rtv, char *string)
{
	char		**buffer;
	int			error;

	error = 1;
	buffer = ft_strsplit(&string[7], ',');
	if (is_num(buffer[0]))
	{
		if (is_num(buffer[1]))
		{
			if (is_num(buffer[2]))
			{
				if (buffer[3] == NULL)
				{
					error = 0;
					parse_cam_add(rtv, buffer);
				}
			}
		}
	}
	if (error)
		parse_cam_error(rtv);
	parse_cam_free(buffer);
}

void	parse_cam_add(t_rtv *rtv, char **buffer)
{
	rtv->camera.z = (double)ft_atoi(buffer[2]);
	rtv->camera.x = (double)ft_atoi(buffer[0]);
	rtv->camera.y = (double)ft_atoi(buffer[1]);
}

void	parse_cam_error(t_rtv *rtv)
{
	ft_putendl("CAM INFO ERROR!!!");
	rtv->camera.z = -50;
	rtv->camera.x = 1;
	rtv->camera.y = 1;
}

void	parse_cam_free(char **buffer)
{
	free(buffer[2]);
	free(buffer[1]);
	free(buffer);
	free(*buffer);
}

int		parse_light(t_rtv *rtv)
{
	t_list		*temporary;
	t_light		light;
	int			error;

	error = 0;
	temporary = NULL;
	if (parse_intense(rtv, &(light.intense)))
	{
		if (parse_pos(rtv, &(light.position)))
		{
			parse_light_add(temporary, rtv, light);
			return (1);
		}
	}
	parse_light_error();
	return (0);
}

void	parse_light_add(t_list *temporary, t_rtv *rtv, t_light light)
{
	temporary = ft_lstnew(&(light), sizeof(t_light));
	temporary->content_size = 444;
	ft_lstadd(&(rtv->light), temporary);		
}

void	parse_light_error(void)
{
	ft_putendl("LIGHT INFO ERROR!!!");
}