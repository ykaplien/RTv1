/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:45 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:46 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RTV1_H
# define FT_RTV1_H

# define BACKGROUND 0
# define CYL 442
# define CONE 443
# define LIGHT 444
# define WIN_PTR rtv->win_ptr
# define MLX_PTR rtv->mlx_ptr
# define IMG_PTR rtv->img_ptr
# define WIN_X 1000
# define WIN_Y 1000
# define PLANE 440
# define SPHERE 441
# define D 1.0
# define PI (3.14 / 180)
# define MIN_REND_DIST 0.1
# define MAX_REND_DIST 600000

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include "math.h"
# include "mlx.h"
# include "../libft/libft.h"

typedef struct	s_clo		// clos
{
	t_list		*object;	//obj
	double		closer;		//clost
	double		y;
}				t_clo;

typedef struct	s_vector
{
	double		dot1;			// t1
	double		dot2;			// t2
	double		x;
	double		y;
	double		z;
	double		t;
	double		result;			//result
}				t_vector;

typedef struct	s_light
{
	t_vector	position;
	t_vector	direction;
	double		intense;
}				t_light;

typedef struct	s_plane
{
	double		r;
	t_vector	center;		//c
	t_vector	vector;		//v
	int			color;
	double		reflect;
}				t_plane;

typedef struct	s_cylinder
{
	double		radius;		//r
	t_vector	center;		//c
	t_vector	vector;		//v
	int			color;
	double		reflect;
}				t_cylinder;

typedef struct	s_sphere
{
	double		radius;		//r
	t_vector	center;		//c
	int			color;
	double		reflect;
}				t_sphere;

typedef struct	s_cone
{
	double		angle;	 // a
	t_vector	center;  // c
	t_vector	vector;  // v
	int			color;
	double		reflect;
}				t_cone;

typedef struct	s_obj
{
	t_sphere	*sphere;
	t_cone		*cone;
	t_plane		*plane;
	t_cylinder	*cylinder;
}				t_obj;

typedef struct	s_hide // vec
{
	t_vector	q;		// d
	t_vector	w;		// v
	t_vector	e;		// n
	t_vector	r;		// p
	t_vector	t;		// l
	t_vector	y;		// o
}				t_hide;

typedef struct	s_rtv
{
	int			fd;
	t_vector	camera;		//cam
	t_vector	angels;		//rot
	void		*img_ptr;
	void		*win_ptr;
	void		*mlx_ptr;
	char		*img;
	int			bpp;
	int			endian;
	double		closest;
	double		d;
	int			size_line;
	t_clo		clos;
	t_list		*obj;
	t_list		*light;
}				t_rtv;

int			event_handler(int key_code, t_rtv *rtv);
void		ft_close(t_rtv *rtv);
int			scene_check(t_rtv *rtv);
int 		scene_check_add(t_list *src);
void		main2(t_rtv *rtv);
void		mlx_activities(t_rtv *rtv);
void		mlx_activities_hooks(t_rtv *rtv);
void		error(int error);
int			closer(t_rtv *rtv);
int			open_file(t_rtv *rtv, char *file_name);
int			is_num(char *string);	//checked
int			rgb_to_hex(t_vector color);	//checked

void		parse_scene(t_rtv *rtv);
void		parse_cam(t_rtv *rtv, char *string);	//checked
void		parse_cam_add(t_rtv *rtv, char **buffer);	//checked
void		parse_cam_error(t_rtv *rtv);	//checked
void		parse_cam_free(char **buffer);	//checked
int			parse_light(t_rtv *rtv);	//checked
void		parse_light_add(t_list *temporary, t_rtv *rtv, t_light light);	//checked
void		parse_light_error(void);	//checked
int			parse_intense(t_rtv *rtv, double *intense);	//checked
int			parse_intense_add(double temporary, double *intense);	//checked
int			parse_pos(t_rtv *rtv, t_vector *position);	//checked
void		parse_pos_add(char **buffer, t_vector *position);	//checked
void		parse_pos_free(char **buffer);	//checked
int			parse_pos_add_add(char **buffer);	//checked
void		parse_rotation(t_rtv *rtv, char *string); //checked
void		parse_rotation_add(t_rtv *rtv, char **temporary); //checked
void		parse_rotation_free(char **temporary); //checked
void		parse_rotation_error(t_rtv *rtv); //checked
int			parse_sphere(t_rtv *rtv);
void		parse_sphere_add(t_list *temporary, t_sphere new_sphere, t_rtv *rtv);
void		parse_sphere_error(void);
int			parse_color_add(char **temporary);	//checked
void		parse_color_free(char **temporary);	//checked
int			parse_color(t_rtv *rtv, int *color);	//checked
int			parse_reflect(t_rtv *rtv, double *rofl);	//checked
int			parse_reflect_add(double temporary, double *rofl);	//checked
int			parse_radius(t_rtv *rtv, double *dest);	//checked
int			parse_radius_add(double temporary, double *dest);	//checked
int			parse_center(t_rtv *rtv, t_vector *destenation);	//checked
void		parse_center_add(char **string1, t_vector *destenation, char *s);	//checked
void		parse_center_free(char **string1);	//checked
void		parse_cone_add(t_list *temporary, t_cone new_cone, t_rtv *rtv);
int			parse_cone(t_rtv *rtv);
void		parse_cone_error(void);
int			parse_normal(t_rtv *rtv, t_vector *dest);	//checked
void		parse_normal_add(t_vector *dest, char **string2);	//checked
void		parse_normal_free(char **string2);	//checked
int			parse_plane(t_rtv *rtv);	//checked
void		parse_plane_add(t_list *temporary, t_plane plane, t_rtv *rtv);	//checked
void		parse_plane_error(void);	//checked
int			parse_angle(t_rtv *rtv, double *angle);	//checked
int			parse_angle_add(char *string, double temporary, double *angle);	//checked
void		parse_cylinder_error(void);
int			parse_cylinder(t_rtv *rtv);
void		parse_cylinder_add(t_list *temporary, t_cylinder dest, t_rtv *rtv);

t_vector	vector_normalization(t_vector source);
double		scalar_product(t_vector x, t_vector y);
void		ray_tracing(t_rtv *rtv);
t_vector	canvas_view(double xy[2]);
t_vector	recalc_pov(t_vector angels, t_vector viewport);
void		r1(double *ver, double *glub, double hor);
void		r2(double *hor, double *glub, double ver);
void		r3(double *hor, double *ver, double glub);
t_vector	vector_add(double x, double y, double z, double unknown); // init_vector
t_vector	vec_normalization(t_vector source);
t_vector	vec_minus(t_vector f, t_vector s);
t_vector	vec_plus(t_vector f, t_vector s);
t_vector	vec_mult(t_vector a, double mult);
double		vec_length(t_vector src);
int			ray_trace(t_vector hz, t_list *scene, t_vector w, t_rtv *all);
t_clo		find_clo(t_list *scene, t_vector camera, t_vector hz, double min);
t_vector	ray_intersect(t_vector d, t_vector o, t_list *list);
t_vector	sphere_intersect(t_sphere *sphere, t_vector o, t_vector d);
t_vector	cyl_intersect(t_cylinder *cyl, t_vector o, t_vector d);
t_vector	cone_intersect(t_cone *c, t_vector o, t_vector d);
t_vector	plane_intersect(t_plane *plane, t_vector o, t_vector d);
void		figure_perpendicular(t_clo *object, t_hide *ray);
void		perpendicular_s(t_sphere *src, t_hide *ray);
void		perpendicular_co(t_cone *src, t_hide *ray, double vec_amount);
void		perpendicular_cy(t_cylinder *src, t_hide *ray, double vec_amount);
void		perpendicular_p(t_plane *src, t_hide *ray);

#endif