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

# define LIGHT 42
# define SPHERE 43
# define CONE 44
# define PLANE 45
# define CYLINDER 46

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
	double		a;
	t_vector	c;
	t_vector	v;
	int			color;
	double		reflect;
}				t_cone;

typedef struct s_plane
{
	double		r;
	t_vector	c;
	t_vector	v;
	int			color;
	double		reflect;
}				t_plane;

typedef struct s_cylinder
{
	double		r;
	t_vector	c;
	t_vector	v;
	int			color;
	double		reflect;
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
	t_vector	cam;
	t_list		*light;
	t_list		*scene;
}				t_rtv;

void	error(int error);
void	openFile(char **argv, t_object *obj, t_rtv *rtv);
int		rgbToInt(t_vector color);

void	parseScene(t_object *obj, t_rtv *rtv);
void	parseCam(char *line, t_rtv *rtv);

void	parseLight(t_rtv *rtv);
int		parsePosition(t_rtv *rtv, t_vector *position);
int		parseIntense(t_rtv *rtv, double *intense);

void	parseSphere(t_rtv *rtv);
int		parseSpecular(t_rtv *rtv, double *specular);
int		parseRadius(t_rtv *rtv, double *radius);
int		parseColor(t_rtv *rtv, int *color);


#endif