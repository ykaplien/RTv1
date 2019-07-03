/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector		sphere_intersect(t_sphere *sphere, t_vector o, t_vector d)
{
	t_vector	oc;
	t_vector	a;
	t_vector	k;
	double		disc;

	a = vector_add(0, 0, 0, 0);
	oc = vec_minus(o, sphere->center);
	k.x = scalar_product(d, d);
	k.y = 2 * scalar_product(oc, d);
	k.z = scalar_product(oc, oc) - sphere->radius * sphere->radius;
	disc = k.y * k.y - 4 * k.x * k.z;
	if (disc < 0)
	{
		a.dot1 = 600000;
		a.dot2 = 600000;
		return (a);
	}
	a.dot1 = (-k.y + sqrt(disc)) / (2 * k.x);
	a.dot2 = (-k.y - sqrt(disc)) / (2 * k.x);
	return (a);
}

t_vector		cyl_intersect(t_cylinder *cyl, t_vector o, t_vector d)
{
	t_vector	oc;
	t_vector	a;
	t_vector	k;
	double		disc;

	a = vector_add(0, 0, 0, 0);
	oc = vec_minus(o, cyl->center);
	k.x = scalar_product(d, d) - scalar_product(d, cyl->vector) * scalar_product(d, cyl->vector);
	k.y = 2 * (scalar_product(oc, d) - scalar_product(cyl->vector, d) * scalar_product(oc, cyl->vector));
	k.z = scalar_product(oc, oc) - scalar_product(oc, cyl->vector) * scalar_product(oc, cyl->vector) - cyl->radius * cyl->radius;
	disc = k.y * k.y - 4 * k.x * k.z;
	if (disc < 0)
	{
		a.dot1 = 600000;
		a.dot2 = 600000;
		return (a);
	}
	a.dot1 = (-k.y + sqrt(disc)) / (2 * k.x);
	a.dot2 = (-k.y - sqrt(disc)) / (2 * k.x);
	return (a);
}

t_vector		cone_intersect(t_cone *c, t_vector o, t_vector d)
{
	t_vector	oc;
	t_vector	a;
	t_vector	k;
	double		disc;

	a = vector_add(0, 0, 0, 0);
	oc = vec_minus(o, c->center);
	k.x = scalar_product(d, d) - (1 + (c->angle) * (c->angle)) * scalar_product(d, c->vector) * scalar_product(d, c->vector);
	k.y = 2 * (scalar_product(d, oc) - (1 + (c->angle) * (c->angle)) * scalar_product(d, c->vector)
			* scalar_product(oc, c->vector));
	k.z = scalar_product(oc, oc) - (1 + (c->angle) * (c->angle)) * scalar_product(oc, c->vector) * scalar_product(oc, c->vector);
	disc = k.y * k.y - 4 * k.x * k.z;
	if (disc < 0)
	{
		a.dot1 = 600000;
		a.dot2 = 600000;
		return (a);
	}
	a.dot1 = (-k.y + sqrt(disc)) / (2 * k.x);
	a.dot2 = (-k.y - sqrt(disc)) / (2 * k.x);
	return (a);
}

t_vector		plane_intersect(t_plane *plane, t_vector o, t_vector d)
{
	t_vector	oc;
	t_vector	a;
	double		i;
	double		j;

	a = vector_add(0, 0, 0, 0);
	oc = vec_minus(plane->center, o);
	i = scalar_product(oc, plane->vector);
	j = scalar_product(d, plane->vector);
	if (j == 0 || ((i / j) < 0))
	{
		a.dot1 = 600000;
		a.dot2 = 600000;
		return (a);
	}
	a.dot1 = i / j;
	a.dot2 = i / j;
	return (a);
}

