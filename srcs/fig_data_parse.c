/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fig_data_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	figure_perpendicular(t_clo *object, t_hide *ray)
{
	if ((object->object)->content_size == 441)
		perpendicular_s((t_sphere *)((object->object)->content), ray);
	else if ((object->object)->content_size == 443)
		perpendicular_co((t_cone *)((object->object)->content), ray, object->closer);
	else if ((object->object)->content_size == 442)
		perpendicular_cy((t_cylinder *)((object->object)->content), ray, object->closer);
	else if ((object->object)->content_size == 440)
		perpendicular_p((t_plane *)((object->object)->content), ray);
}