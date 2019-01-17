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
# define MAX_RENDER 60000
# define MIN_RENDER 1
# define BACKGROUND 0xffffff
// # define DOT(d1, d2) (d1[0] * d2[0] + d1[1] * d2[1] + d1[2] * d2[2])

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_dot
{
	double		x;
	double		y;
	double		z;
}				t_dot;

typedef struct	s_inter
{
	double		t1;
	double		t2;
}				t_inter;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	double		intersect;
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

typedef struct	s_clo
{
	t_object	*object;
	double		distance; //closest
	double		z;

}				t_clo;

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
	// double		clo;
}				t_rtv;

void	canvas_to_viewport(t_rtv *rtv, int x, int y);
void	ray_tracing(t_rtv *rtv);
int		sphere_color(t_list *list);
void	pixel_to_img(t_rtv *rtv, int x, int y, int color);
double	vec_scalar(t_vector a, t_vector b);
t_vector	vec_diff(t_vector a, t_vector b);


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

int		trace_ray(t_rtv *rtv);
t_clo	clo_object(t_rtv *rtv);
t_inter	ray_intersect(t_rtv *rtv,t_list *list);
t_inter	sphere_intersect(t_rtv *rtv, t_sphere *sphere);


#endif