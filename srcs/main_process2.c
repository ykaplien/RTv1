/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		r3(double *hor, double *ver, double glub)
{
	double		hor2;
	double		ver2;

	hor2 = *hor;
	ver2 = *ver;
	*hor = hor2 * cos(glub * PI) - ver2 * sin(glub * PI);
	*ver = hor2 * sin(glub * PI) + ver2 * cos(glub * PI);
}

t_vector	vector_normalization(t_vector source)
{
	double		length[2];
	t_vector	destenation;

	length[0] = scalar_product(source, source);
	length[1] = sqrt(length[0]);
	length[1] = (length[1] == 0) ? 1 : length[1];
	destenation.x = source.x / length[1];
	destenation.y = source.y / length[1];
	destenation.z = source.z / length[1];
	return (destenation);
}

int			ray_trace(t_vector hz, t_list *scene, t_vector w, t_rtv *rtv) // d - hz  ;; o - w (camera) ;; list - scene
{
	t_hide		hide;	// vec
	t_clo		f_obj;	// closer

	if (rtv)
		;
	f_obj.object = 0;
	f_obj = find_clo(scene, w, hz, MIN_REND_DIST); // продолжать
	if (f_obj.object == NULL)
		return (BACKGROUND);
	hide.y = w; // y -> o
	hide.q = hz; // q -> d
	hide.w = vec_minus(vector_add(0, 0, 0, 0), hz);
	hide.r = vec_plus(vec_mult(hz, f_obj.closer), w);
	figure_perpendicular(&f_obj, &hide);
	return (0); // заглушка
}

t_clo		find_clo(t_list *scene, t_vector camera, t_vector hz, double min)
{
	t_vector	hide;	// a
	t_clo		clo;	// closer

	hide = vector_add(MAX_REND_DIST, MAX_REND_DIST, MAX_REND_DIST, MAX_REND_DIST);
	clo.closer = MAX_REND_DIST;
	clo.object = 0;
	while (scene && 0 < (scene->content_size))
	{
		hide = ray_intersect(hz, camera, scene); // нету 
		if (hide.dot1 >= min && hide.dot1 <= 600000 && hide.dot1 < clo.closer)
		{
			clo.object = scene;
			clo.closer = hide.dot1;
		}
		if (hide.dot2 >= min && hide.dot2 <= 600000 && hide.dot2 < clo.closer)
		{
			clo.object = scene;
			clo.closer = hide.dot2;
		}
		scene = scene->next;
	}
	return (clo);
}

t_vector		ray_intersect(t_vector d, t_vector o, t_list *list)
{
	t_vector	res;

	res = vector_add(0, 0, 0, 0);
	if (list->content_size == SPHERE)
		res = sphere_intersect((t_sphere *)(list->content), o, d);	//	нету
	else if (list->content_size == CONE)
		res = cone_intersect((t_cone *)(list->content), o, d);	//	нету
	else if (list->content_size == PLANE)
		res = plane_intersect((t_plane *)(list->content), o, d);	//	нету
	else if (list->content_size == CYL)
		res = cyl_intersect((t_cylinder *)(list->content), o, d);	//	нету
	else
		res = vector_add(MAX_REND_DIST, MAX_REND_DIST, MAX_REND_DIST, MAX_REND_DIST);
	return (res);
}