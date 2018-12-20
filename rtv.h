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

#ifndef RTV_H
# define RTV_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct 	s_rtv
{
	int			figuresCount;
}				t_rtv;

typedef	struct	s_dot
{
	double		x;
	double		y;
	double		z;
}				t_dot;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_light
{
	char		*type;
	double		intensivity;
	t_dot		direction;
}				t_light;

typedef	struct	s_sphere
{
	t_dot		center;
	double		radius;
	int			specular;
	double		reflective;
}				t_vector;

typedef	struct	s_camera
{
	t_dot		center;
}				t_camera;

void	error(int error);
void	parseScene(t_rtv *rtv, char* mapName);
void	parseLine(t_rtv *rtv, char *line);
int		spotObject(char *line);
void	parseCamera(t_rtv *rtv, char *line);
void	parseSphere(t_rtv *rtv, char *line);


#endif