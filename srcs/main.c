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

void	open_file(char **argv, t_object *obj, t_rtv *rtv)
{
	rtv->fd = open(argv[1], O_RDONLY);
	if (rtv->fd == -1)
		error(2);
	parse_scene(obj, rtv);
}

void	parse_scene(t_object *obj, t_rtv *rtv)
{
	char		*line;
	t_list		*tmp;

	while (get_next_line(rtv->fd, &line) > 0)
	{
		if (ft_strncmp(line, "camera:", 7) == 0)
			parse_cam(line, rtv);
		else if (ft_strncmp(line, "#light", 6) == 0)
			parse_light(rtv);
		else if (ft_strncmp(line, "#sphere", 7) == 0)
			parse_sphere(rtv);
		else if (ft_strncmp(line, "#cone", 5) == 0)
			parse_cone(rtv);
		else if (ft_strncmp(line, "#plane", 6) == 0)
			parse_plane(rtv);
		else if (ft_strncmp(line, "#cylinder", 9) == 0)
			parse_cylinder(rtv);
	}
}

void	parse_light(t_rtv *rtv)
{
	t_light		light;
	t_list		*list;

	if (parse_position(rtv, &(light.position)) && (parse_intense(rtv, &(light.intense))))
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

int		parse_position(t_rtv *rtv, t_vector *position)
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

int		parse_intense(t_rtv *rtv, double *intense)
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

void	parse_sphere(t_rtv *rtv)
{
	t_sphere	sphere;
	t_list		*list;

	if (parse_position(rtv, &(sphere.position)) && 
		(parse_specular(rtv, &(sphere.specular))) && 
		(parse_radius(rtv, &(sphere.radius))) && 
		(parse_color(rtv, &(sphere.color))))
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

int		parse_specular(t_rtv *rtv, double *specular)
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

int		parse_radius(t_rtv *rtv, double *radius)
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

int		parse_color(t_rtv *rtv, int *color)
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
		res = rgb_to_int(colorVector);
		// printf("R%f\n", colorVector.x);
		// printf("G%f\n", colorVector.y);
		// printf("B%f\n", colorVector.z);
		*color = res;
		return (1);
	}
	return (0);
}

int		rgb_to_int(t_vector color)
{
	int			res;

	res = color.x;
	res = (res << 8) + color.y;
	res = (res << 8) + color.z;
	return (res);
}

void	parse_cone(t_rtv *rtv)
{
	t_cone		cone;
	t_list		*list;

	if (parse_position(rtv, &(cone.position)) &&
		(parse_normal(rtv, &(cone.normal))) &&
		(parse_angle(rtv, &(cone.angle))) &&
		(parse_specular(rtv, &(cone.specular))) &&
		(parse_color(rtv, &(cone.color))))
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

int		parse_normal(t_rtv *rtv, t_vector *normal)
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

int		parse_angle(t_rtv *rtv, double *angle)
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

void	parse_plane(t_rtv *rtv)
{
	t_plane		plane;
	t_list		*list;

	if (parse_position(rtv, &(plane.position)) &&
		(parse_normal(rtv, &(plane.normal))) &&
		(parse_specular(rtv, &(plane.specular))) &&
		(parse_color(rtv, &(plane.color))))
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

void	parse_cylinder(t_rtv *rtv)
{
	t_cylinder		cylinder;
	t_list		*list;

	if (parse_position(rtv, &(cylinder.position)) &&
		(parse_normal(rtv, &(cylinder.normal))) &&
		(parse_specular(rtv, &(cylinder.specular))) &&
		(parse_radius(rtv, &(cylinder.radius))) &&
		(parse_color(rtv, &(cylinder.color))))
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

void	parse_cam(char *line, t_rtv *rtv)
{
	char		**tmp;

	tmp = ft_strsplit(&line[7], ',');
	rtv->cam.x = (double)ft_atoi(tmp[0]);
	rtv->cam.y = (double)ft_atoi(tmp[1]);
	rtv->cam.z = (double)ft_atoi(tmp[2]);
	printf("CAM %f %f %f\n\n", rtv->cam.x, rtv->cam.y, rtv->cam.z);
	free(tmp);
}

void	print_scene(t_rtv *rtv)
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

void	print_light(t_rtv *rtv)
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

void	canvas_init(t_rtv *rtv)
{
	int			sizeLine;
	int			bpp;
	int			endian;

	rtv->mlxPtr = mlx_init();
	rtv->winPtr = mlx_new_window(rtv->mlxPtr, WIN_X, WIN_Y, "RTv1");
	rtv->imgPtr = mlx_new_image(rtv->mlxPtr, WIN_X, WIN_Y);
	rtv->imgSrc = (int*)mlx_get_data_addr(rtv->imgPtr, &bpp, &sizeLine, &endian);
}

int		event_handle(int key, t_rtv *rtv)
{
	if (key == 53)
	{
		free(rtv);
		exit(0);
	}
	return (0);
}


void	canvas_to_viewport(t_rtv *rtv, int x, int y)
{
	rtv->viewport.x = x / WIN_X;
	rtv->viewport.y = y / WIN_Y;
	rtv->viewport.z = 1;										//		Это d, расстояние до плоскости проекции;
}

t_vector	vec_diff(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = b.x - a.x;
	res.y = b.y - a.y;
	res.z = b.z - a.z;
	return (res);
}

double	vec_scalar(t_vector a, t_vector b)
{
	double		res;

	res = a.x * b.x + a.y * b.y + a.z * b.z;
	return (res);
}

void	pixel_to_img(t_rtv *rtv, int x, int y, int color)
{
	if (x >= 0 && x < WIN_X && y >= 0 && y < WIN_Y)
		*(int *)(rtv->imgSrc + ((x + y * WIN_X) * 4)) = color;
}

int		sphere_color(t_list list)
{
	t_sphere	*res;

	res = (t_sphere*)list.content;
	return (res->color);
}

void	ray_tracing(t_rtv *rtv)
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
			canvas_to_viewport(rtv, x, y);
			rayResult = trace_ray(rtv); // её нету ещё
			y++;

		}
		x++;
	}
	mlx_put_image_to_window(rtv->mlxPtr, rtv->winPtr, rtv->imgPtr, 0, 0);
}

int		trace_ray(t_rtv *rtv)
{
	t_list		list;
	t_clo	 	clo;

	list = *(rtv->scene);
	clo.object = NULL;
	clo = clo_object(rtv);
	if (clo.object == NULL)
		return (BACKGROUND);
	return (sphere_color(clo.object));
}

t_clo	clo_object(t_rtv *rtv)
{
	t_clo		clo;
	t_inter		inter;
	t_list		*list;

	clo.distance = MAX_RENDER + 1;
	clo.obj = NULL;
	list = rtv->scene;
	while (list)
	{
		inter = ray_intersect(rtv, list);
		if (inter.t1 >= MIN_RENDER && inter.t1 <= MAX_RENDER && inter.t1 < clo.distance)
		{
			clo.obj = list;
			clo.distance = inter.t1;
		}
		if (inter.t2 >= MIN_RENDER && inter.t2 <= MAX_RENDER && inter.t2 < clo.distance)
		{
			clo.obj = list;
			clo.distance = inter.t2;
		}
		list = list->next;
	}
	return (clo);
}

t_inter	ray_intersect(t_rtv *rtv,t_list list)
{
	t_inter		res;

	if (list->content_size == SPHERE)
		res = sphere_intersect(rtv, (t_sphere *)list->content);
	return (res);
}

t_inter	sphere_intersect(t_rtv *rtv, t_sphere sphere)
{
	t_vector	OC;
	t_vector	k;
	t_inter		res;
	double		discriminant;

	OC = vec_diff(sphere.position, rtv->cam);
	k.x = vec_scalar(rtv->cam, rtv->cam);
	k.y = 2 * vec_scalar(OC, rtv->cam);
	k.z = vec_scalar(OC, OC) - (sphere.radius * sphere.radius);
	discriminant = (k.y * k.y) - (4 * k.x * k.z);
	if (discriminant < 0)
	{
		res.t1 = MAX_RENDER;
		res.t2 = MAX_RENDER;
		return (res);
	}
	res.t1 = (-k.y + sqrt(discriminant)) / (2 * k.x);
	res.t2 = (-k.y - sqrt(discriminant)) / (2 * k.x);
	return (res);
}

int		main(int argc, char **argv)
{
	t_rtv		*rtv;
	t_object	*obj;

	if (argc == 2)
	{
		rtv = (t_rtv*)ft_memalloc(sizeof(t_rtv));
		obj = (t_object*)ft_memalloc(sizeof(t_object));
		open_file(argv, obj, rtv);
		print_scene(rtv);
		print_light(rtv);
		canvas_init(rtv);
		mlx_hook(rtv->winPtr, 2, 5, event_handle, rtv);
		mlx_loop(rtv->mlxPtr);
	}
	else
		error(1);
	return (0);
}