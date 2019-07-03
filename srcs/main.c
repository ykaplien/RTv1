/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		main(int argc, char  **argv)
{
	t_rtv		*rtv;

	if (argc == 2)
	{
		rtv = (t_rtv*)ft_memalloc(sizeof(t_rtv));
		if (open_file(rtv, argv[1]))
		{
			main2(rtv);
		}
	}
	else
		error(1);
	return 0;
}

int		open_file(t_rtv *rtv, char *file_name)
{
	rtv->fd = open(file_name, O_RDONLY);
	if (rtv->fd == -1)
		error(2);
	return (1);
}

void	parse_scene(t_rtv *rtv)
{
	char		*string;
	int			check;

	check = 0;
	while (get_next_line(rtv->fd, &string) > 0)
	{
		if (ft_strncmp(string, "camera:", 7) == 0)
			parse_cam(rtv, string);
		else if (ft_strncmp(string, "#light", 6) == 0)
			parse_light(rtv);
		else if (ft_strncmp(string, "rotation", 9) == 0)
			parse_rotation(rtv, string);
		else if (ft_strncmp(string, "#sphere", 7) == 0)
			parse_sphere(rtv);
		else if (ft_strncmp(string, "#cone", 5) == 0)
			parse_cone(rtv);							
		else if (ft_strncmp(string, "#plane", 6) == 0)
			parse_plane(rtv);
		else if (ft_strncmp(string, "#cylinder", 9) == 0)
			parse_cylinder(rtv);
		free(string);
		check++;
	}
	if (!check)
		error(3);
}
