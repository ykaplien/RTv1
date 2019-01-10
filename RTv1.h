/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:04:09 by ykaplien          #+#    #+#             */
/*   Updated: 2018/10/25 15:04:10 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RTV1_H
# define FT_RTV1_H

# define WIN_X 1200
# define WIN_Y 1200
# define LIGHT 442
# define SPHERE 443
# define CONE 444
# define PLANE 445
# define CYLINDER 446

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;

}				t_vector;

typedef struct s_sphere
{
	t_vector	position;
	double		specular;
	double		radius;
	int			color;
}				t_sphere;

typedef struct s_cone
{
	t_vector	position;
	t_vector	normal;
	double		angle;
	double		specular;
	int			color;
}				t_cone;

typedef struct s_plane
{
	t_vector	position;
	t_vector	normal;
	double		specular;
	int			color;
}				t_plane;


typedef struct s_cylinder
{
	t_vector	position;
	t_vector	normal;
	double		specular;
	double		radius;
	int			color;
}				t_cylinder;

typedef struct s_light
{
	t_vector	position;
	double		intense;
	t_vector	v;
}				t_light;

typedef struct s_object
{
	t_sphere	*sphere;
	t_cone		*cone;
	t_plane		*plane;
	t_cylinder	*cylinder;
}				t_object;

typedef struct	s_rtv
{
	int			fd;

	void		*mlxPtr;
	void		*winPtr;
	void		*imgPtr;
	int			*imgSrc;

	t_vector	cam;
	t_list		*light;
	t_list		*scene;

	t_vector	viewport;
}				t_rtv;

void	canvas_to_viewport(t_rtv *rtv, int x, int y);
void	ray_tracing(t_rtv *rtv);


void	error(int error);
void	open_file(char **argv, t_object *obj, t_rtv *rtv);
int		rgb_to_int(t_vector color);
void	print_scene(t_rtv *rtv);
void	print_light(t_rtv *rtv);
void	canvas_init(t_rtv *rtv);
int		event_handle(int key, t_rtv *rtv);

void	parse_scene(t_object *obj, t_rtv *rtv);
void	parse_cam(char *line, t_rtv *rtv);
void	parse_light(t_rtv *rtv);
int		parse_position(t_rtv *rtv, t_vector *position);
int		parse_intense(t_rtv *rtv, double *intense);
void	parse_sphere(t_rtv *rtv);
int		parse_specular(t_rtv *rtv, double *specular);
int		parse_radius(t_rtv *rtv, double *radius);
int		parse_color(t_rtv *rtv, int *color);
void	parse_cone(t_rtv *rtv);
int		parse_normal(t_rtv *rtv, t_vector *normal);
int		parse_angle(t_rtv *rtv, double *angle);
void	parse_plane(t_rtv *rtv);
void	parse_cylinder(t_rtv *rtv);

#endif