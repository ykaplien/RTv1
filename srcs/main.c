/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:04:09 by ykaplien          #+#    #+#             */
/*   Updated: 2018/10/25 15:04:10 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../RTv1.h"

void	error(int error)
{
	if (error == 1)
		ft_putendl("Usage: ./RTv1 [fileaname]");
	else if (error == 2)
		ft_putendl("Can't open file, try another one or check filename!");
	exit(0);
}

void	openFile(char **argv, t_object *obj, t_rtv *rtv)
{
	rtv->fd = open(argv[1], O_RDONLY);
	if (rtv->fd == -1)
		error(2);
	parseScene(obj, rtv);
}

void	parseScene(t_object *obj, t_rtv *rtv)
{
	char		*line;
	t_list		*tmp;

	while (get_next_line(rtv->fd, &line) > 0)
	{
		if (ft_strncmp(line, "camera:", 7) == 0)
			parseCam(line, rtv);
		else if (ft_strncmp(line, "#light", 6) == 0)
			parseLight(rtv);
		else if (ft_strncmp(line, "#sphere", 7) == 0)
			parseSphere(rtv);
		// else if (ft_strncmp(line, "#cone", 5) == 0)
		// 	parseCone;
		// else if (ft_strncmp(line, "#plane", 6) == 0)
		// 	parsePlane;
		// else if (ft_strncmp(line, "#cylinder", 9) == 0)
		// 	parseCylinder;
	}
}

void	parseLight(t_rtv *rtv)
{
	t_light		light;
	t_list		*list;

	if (parsePosition(rtv, &(light.position)) && (parseIntense(rtv, &(light.intense))))
	{
		list = ft_lstnew(&light, sizeof(t_light));
		list->content_size = LIGHT;
		ft_lstadd(&(rtv->light), list);
		return ;
		// printf("coords %f %f %f\n", light.position.x, light.position.y, light.position.z);
		// printf("intense %f\n", light.intense);
	}
	ft_putendl("Missing parameters for light!!!");
}

int		parsePosition(t_rtv *rtv, t_vector *position)
{
	char	*line;
	char	**data;

	if ((get_next_line(rtv->fd, &line) > 0) && (ft_strncmp(line, " position:", 10) == 0))
	{
		data = ft_strsplit(&line[10], ',');
		position->x = (double)ft_atoi(data[0]);
		position->y = (double)ft_atoi(data[1]);
		position->z = (double)ft_atoi(data[2]);
		// printf("%f %f %f\n", position->x, position->y, position->z);
		free(data);
		return (1);
	}
	return (0);
}

int		parseIntense(t_rtv *rtv, double *intense)
{
	char	*line;
	double	data;

	if ((get_next_line(rtv->fd, &line) > 0) && (ft_strncmp(line, " intense:", 9) == 0))
	{
		data = (double)ft_atoi(&line[9]);
		data = (data < 0) ? -data : data;
		*intense = (data > 100) ?  : data / 10;
		return (1);
	}
	return (0);
}

void	parseSphere(t_rtv *rtv)
{
	t_sphere	sphere;
	t_list		*list;

	if (parsePosition(rtv, &(sphere.position)) && 
		(parseSpecular(rtv, &(sphere.specular))) && 
		(parseRadius(rtv, &(sphere.radius))) && 
		(parseColor(rtv, &(sphere.color))))
	{
		// printf("SPHERE position: %f %f %f\n", sphere.position.x, sphere.position.y, sphere.position.z);
		// printf("specular %f\n", sphere.specular);
		// printf("radius %f\n", sphere.radius);
		// printf("color %d\n", sphere.color);
		list = ft_lstnew(&sphere, sizeof(t_sphere));
		list->content_size = SPHERE;
		ft_lstadd(&(rtv->scene), list);
	}
	else
		ft_putendl("Missing parameters for sphere!!!");
}

int		parseSpecular(t_rtv *rtv, double *specular)
{
	char		*line;
	double		data;

	if ((get_next_line(rtv->fd, &line) > 0) && (ft_strncmp(line, " specular:", 10) == 0))
	{
		data = (double)ft_atoi(&line[10]);
		data = (data < 0) ? 0 : data;
		*specular = (data > 100) ? data : data * 10;
		return (1);
	}
	return (0);
}

int		parseRadius(t_rtv *rtv, double *radius)
{
	char		*line;
	double		data;

	if ((get_next_line(rtv->fd, &line) > 0) && (ft_strncmp(line, " radius:", 8) == 0))
	{
		data = (double)ft_atoi(&line[8]);
		data = (data < 0) ? 0 : data;
		*radius = data;
		return (1);
	}
	return (0);
}

int		parseColor(t_rtv *rtv, int *color)
{
	int			res;
	char		*line;
	char		**data;
	t_vector	colorVector;

	if ((get_next_line(rtv->fd, &line) > 0) && (ft_strncmp(line, " color:", 7) == 0))
	{
		data = ft_strsplit(&line[7], ',');
		colorVector.x = (double)ft_atoi(data[0]);
		colorVector.y = (double)ft_atoi(data[1]);
		colorVector.z = (double)ft_atoi(data[2]);
		free(data);
		res = rgbToInt(colorVector);
		*color = res;
		return (1);
	}
	return (0);
}

int		rgbToInt(t_vector color)
{
	int			res;

	res = color.x;
	res = (res << 8) + color.y;
	res = (res << 8) + color.z;
	return (res);
}

void	parseCam(char *line, t_rtv *rtv)
{
	char		**tmp;

	tmp = ft_strsplit(&line[7], ',');
	rtv->cam.x = (double)ft_atoi(tmp[0]);
	rtv->cam.y = (double)ft_atoi(tmp[1]);
	rtv->cam.z = (double)ft_atoi(tmp[2]);
	free(tmp);
}

int		main(int argc, char **argv)
{
	t_rtv		*rtv;
	t_object	*obj;

	if (argc == 2)
	{
		rtv = (t_rtv*)ft_memalloc(sizeof(t_rtv));
		obj = (t_object*)ft_memalloc(sizeof(t_object));
		openFile(argv, obj, rtv);
	}
	else
		error(1);
	return (0);
}