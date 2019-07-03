/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fig_perpendicular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	perpendicular_s(t_sphere *src, t_hide *ray)
{
	t_vector	result;

	result = vec_minus(ray->r, src->center);
	ray->e = vec_normalization(result);
}

void	perpendicular_co(t_cone *src, t_hide *ray, double vec_amount)	// src->cone ray->vec vec_amount->t
{
	t_vector	dot1;	// oc
	double		dot2;	// m
	t_vector	dot3;	// pc

	src->vector = vec_normalization(src->vector);
	dot1 = vec_minus(ray->y, src->center);
	dot3 = vec_minus(ray->r, src->center);
	dot2 = scalar_product(ray->q, src->vector) * vec_amount + scalar_product(dot1, src->vector);
	ray->n = vec_minus(dot3, vec_mult(dot2, vec_mult((1 + (src->angle) * (src->angle)), src->vector)));
	ray->n = norm(ray->e);
}

void	perpendicular_cy(t_cylinder *src, t_hide *ray, double vec_amount)	// src->src ray->ray vec_amount->t
{
	t_vector	dot1;	//oc
	double		dot2;	//m 

	src->v = norm(src->vector);
	dot1 = vec_minus(ray->y, src->center);
	dot2 = scalar_product(ray->q, vec_mult(vec_amount, src->vector)) + scalar_product(dot1, src->vector);
	ray->e = minus(vec_minus(ray->r, src->center), vec_mult(dot2, src->vector));
	ray->e = norm(ray->e);
}

// продолжать фиксить ошибки

void	perpendicular_p(t_plane *src, t_hide *ray)
{

}
