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

void	canvasToViewport(int x, int y);
void	rayTracing(t_rtv *rtv);


void	error(int error);
void	openFile(char **argv, t_object *obj, t_rtv *rtv);
int		rgbToInt(t_vector color);
void	printScene(t_rtv *rtv);
void	printLight(t_rtv *rtv);
void	canvasInit(t_rtv *rtv);
int		eventHandle(int key, t_rtv *rtv);

void	parseScene(t_object *obj, t_rtv *rtv);
void	parseCam(char *line, t_rtv *rtv);
void	parseLight(t_rtv *rtv);
int		parsePosition(t_rtv *rtv, t_vector *position);
int		parseIntense(t_rtv *rtv, double *intense);
void	parseSphere(t_rtv *rtv);
int		parseSpecular(t_rtv *rtv, double *specular);
int		parseRadius(t_rtv *rtv, double *radius);
int		parseColor(t_rtv *rtv, int *color);
void	parseCone(t_rtv *rtv);
int		parseNormal(t_rtv *rtv, t_vector *normal);
int		parseAngle(t_rtv *rtv, double *angle);
void	parsePlane(t_rtv *rtv);
void	parseCylinder(t_rtv *rtv);

#endif