/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		ray_tracing(t_rtv *rtv)
{
	t_vector	hz_kak_nazvat;
	int			color;
	double		xy[2];

	xy[0] = -WIN_X / 2;
	while (xy[0] < WIN_X / 2)
	{
		xy[1] = -WIN_Y / 2;
		while (xy[1] < WIN_Y / 2)
		{
			hz_kak_nazvat = recalc_pov(rtv->angels, canvas_view(xy));			//Rairun
			color = ray_trace(hz_kak_nazvat, rtv->obj, rtv->camera, rtv);
			xy[1]++;
		}
		xy[0]++;
	}
}

t_vector	canvas_view(double xy[2])
{
	t_vector	res;
	double		x;
	double		y;

	x = xy[0];
	y = xy[1];
	res.x = (double)(x / WIN_X);
	res.y = (double)(y / WIN_Y);
	res.z = D;
	return (res);
}

t_vector	recalc_pov(t_vector angels, t_vector viewport)
{
	t_vector	dst;
	t_vector	src;

	src = viewport;
	r1(&src.y, &src.z, angels.x);
	r2(&src.x, &src.z, angels.y);
	r3(&src.x, &src.y, angels.z);
	dst = src;
	vec_normalization(dst);
	return (dst);
}

void		r1(double *ver, double *glub, double hor)
{
	double		glub2;
	double		ver2;

	ver2 = *ver;
	glub2 = *glub;
	*ver = ver2 * cos(hor * PI) - glub2 * sin(hor * PI);
	*glub = ver2 * sin(hor * PI) + glub2 * cos(hor * PI);
}

void		r2(double *hor, double *glub, double ver)
{
	double		hor2;
	double		glub2;

	hor2 = *hor;
	glub2 = *glub;
	*glub = glub2 * cos(ver * PI) - hor2 * sin(ver * PI);
	*hor = glub2 * sin(ver * PI) + hor2 * cos(ver * PI);
}
