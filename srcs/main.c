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
		else if (ft_strncmp(line, "#cone", 5) == 0)
			parseCone(rtv);
		else if (ft_strncmp(line, "#plane", 6) == 0)
			parsePlane(rtv);
		else if (ft_strncmp(line, "#cylinder", 9) == 0)
			parseCylinder(rtv);
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
		printf("LIGHT 	position %f %f %f\n", light.position.x, light.position.y, light.position.z);
		printf("		intense %f\n\n", light.intense);
	}
	else
		ft_putendl("Missing parameters for light!!!");
}

int		parsePosition(t_rtv *rtv, t_vector *position)
{
	char	*line;
	char	**data;

	if ((get_next_line(rtv->fd, &line) > 0) && (ft_strncmp(line, " position:", 10) == 0))
	{
		data = ft_strsplit(&line[10], ',');
		if (data[0] && data[1] && data[2])
		{
			position->x = (double)ft_atoi(data[0]);
			position->y = (double)ft_atoi(data[1]);
			position->z = (double)ft_atoi(data[2]);
			// printf("%f %f %f\n", position->x, position->y, position->z);
			free(data);
			return (1);
		}
		free(data);
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
		printf("SPHERE 	position: %f %f %f\n", sphere.position.x, sphere.position.y, sphere.position.z);
		printf("		specular %f\n", sphere.specular);
		printf("		radius %f\n", sphere.radius);
		printf("		color %d\n\n", sphere.color);
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
		// printf("R%f\n", colorVector.x);
		// printf("G%f\n", colorVector.y);
		// printf("B%f\n", colorVector.z);
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

void	parseCone(t_rtv *rtv)
{
	t_cone		cone;
	t_list		*list;

	if (parsePosition(rtv, &(cone.position)) &&
		(parseNormal(rtv, &(cone.normal))) &&
		(parseAngle(rtv, &(cone.angle))) &&
		(parseSpecular(rtv, &(cone.specular))) &&
		(parseColor(rtv, &(cone.color))))
	{
		printf("CONE 	position: %f %f %f\n", cone.position.x, cone.position.y, cone.position.z);
		printf("		normal %f %f %f\n", cone.normal.x, cone.normal.y, cone.normal.z);
		printf("		angle %f\n", cone.angle);
		printf("		specular %f\n", cone.specular);
		printf("		color %d\n\n", cone.color);
		list = ft_lstnew(&cone, sizeof(t_cone));
		list->content_size = CONE;
		ft_lstadd(&(rtv->scene), list);
	}
	else
		ft_putendl("Missing parameters for cone!!!");
}

int		parseNormal(t_rtv *rtv, t_vector *normal)
{
	char		*line;
	char		**data;

	if ((get_next_line(rtv->fd, &line) > 0) && (ft_strncmp(line, " normal:", 8) == 0))
	{
		data = ft_strsplit(&line[8], ',');
		if (data[0] && data[1] && data[2])
		{
			normal->x = (double)ft_atoi(data[0]);
			normal->y = (double)ft_atoi(data[1]);
			normal->z = (double)ft_atoi(data[2]);
			// printf("%f %f %f\n", normal->x, normal->y, normal->z);
			free(data);
			return (1);
		}
		free(data);
	}
	return (0);
}

int		parseAngle(t_rtv *rtv, double *angle)
{
	char		*line;
	double		data;

	if ((get_next_line(rtv->fd, &line) > 0) && (ft_strncmp(line, " angle:", 7) == 0))
	{
		data = (double)ft_atoi(&line[7]) / 2;
		*angle = tan(data);
		return (1);
	}
	return (0);
}

void	parsePlane(t_rtv *rtv)
{
	t_plane		plane;
	t_list		*list;

	if (parsePosition(rtv, &(plane.position)) &&
		(parseNormal(rtv, &(plane.normal))) &&
		(parseSpecular(rtv, &(plane.specular))) &&
		(parseColor(rtv, &(plane.color))))
	{
		printf("PLANE	position: %f %f %f\n", plane.position.x, plane.position.y, plane.position.z);
		printf("		normal %f %f %f\n", plane.normal.x, plane.normal.y, plane.normal.z);
		printf("		specular %f\n", plane.specular);
		printf("		color %d\n\n", plane.color);
		list = ft_lstnew(&plane, sizeof(t_plane));
		list->content_size = PLANE;
		ft_lstadd(&(rtv->scene), list);
	}
	else
		ft_putendl("Missing parameters for plane!!!");
}

void	parseCylinder(t_rtv *rtv)
{
	t_cylinder		cylinder;
	t_list		*list;

	if (parsePosition(rtv, &(cylinder.position)) &&
		(parseNormal(rtv, &(cylinder.normal))) &&
		(parseSpecular(rtv, &(cylinder.specular))) &&
		(parseRadius(rtv, &(cylinder.radius))) &&
		(parseColor(rtv, &(cylinder.color))))
	{
		printf("CYLINDER 	position: %f %f %f\n", cylinder.position.x, cylinder.position.y, cylinder.position.z);
		printf("			normal %f %f %f\n", cylinder.normal.x, cylinder.normal.y, cylinder.normal.z);
		printf("			specular %f\n", cylinder.specular);
		printf("			radius %f\n", cylinder.radius);
		printf("			color %d\n\n", cylinder.color);
		list = ft_lstnew(&cylinder, sizeof(t_cylinder));
		list->content_size = CYLINDER;
		ft_lstadd(&(rtv->scene), list);
	}
	else
		ft_putendl("Missing parameters for plane!!!");
}

void	parseCam(char *line, t_rtv *rtv)
{
	char		**tmp;

	tmp = ft_strsplit(&line[7], ',');
	rtv->cam.x = (double)ft_atoi(tmp[0]);
	rtv->cam.y = (double)ft_atoi(tmp[1]);
	rtv->cam.z = (double)ft_atoi(tmp[2]);
	printf("CAM %f %f %f\n\n", rtv->cam.x, rtv->cam.y, rtv->cam.z);
	free(tmp);
}

void	printScene(t_rtv *rtv)
{
	t_list		*list;
	int			i;

	i = 1;
	list = rtv->scene;
	printf("%s\n", "		SCENE:");
	while (list)
	{
		printf("%d  -->  ", i);
		if (list->content_size == SPHERE)
			printf("SPHERE\n");
		else if (list->content_size == CONE)
			printf("CONE\n");
		else if (list->content_size == PLANE)
			printf("PLANE\n");
		else if (list->content_size == CYLINDER)
			printf("CYLINDER\n");
		i++;
		list = list->next;
	}
}

void	printLight(t_rtv *rtv)
{
	t_list		*list;
	t_light		*light;
	int 		i;

	list = rtv->light;
	i = 1;
	printf("%s\n", "		LIGHT:");
	while (list)
	{
		printf("%d  -->  ", i);
		if (list->content_size == LIGHT)
		{
			light = (t_light*)list->content;
			printf("%f %f %f\n", light->position.x, light->position.y, light->position.z);
		}
		i++;
		list = list->next;
	}
}

void	canvasInit(t_rtv *rtv)
{
	int			sizeLine;
	int			bpp;
	int			endian;

	rtv->mlxPtr = mlx_init();
	rtv->winPtr = mlx_new_window(rtv->mlxPtr, WIN_X, WIN_Y, "RTv1");
	rtv->imgPtr = mlx_new_image(rtv->mlxPtr, WIN_X, WIN_Y);
	rtv->imgSrc = (int*)mlx_get_data_addr(rtv->imgPtr, &bpp, &sizeLine, &endian);
}

int		eventHandle(int key, t_rtv *rtv)
{
	if (key == 53)
	{
		free(rtv);
		exit(0);
	}
	return (0);
}

void	rayTracing(t_rtv *rtv)
{
	int			x;
	int			y;
	int			rayResult;

	x = -WIN_X / 2;
	while (x < WIN_X / 2)
	{
		y = -WIN_Y / 2;
		while (y < WIN_Y / 2)
		{
			canvasToViewport(x, y);
			rayResult = traceRay(); // её нету ещё
			y++;
		}
		x++;
	}
}

void	canvasToViewport(int x, int y)
{
	rtv->viewport.x = x / WIN_X;
	rtv->viewport.y = y / WIN_Y;
	rtv->viewport.z = 1;										//		Это d, расстояние до плоскости проекции;
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
		printScene(rtv);
		printLight(rtv);
		canvasInit(rtv);
		mlx_hook(rtv->winPtr, 2, 5, eventHandle, rtv);
		mlx_loop(rtv->mlxPtr);
	}
	else
		error(1);
	return (0);
}