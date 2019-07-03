/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:30:21 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:30:22 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector		hex_to_rgb(int hex)
{
	t_vector	color;

	color.x = (hex >> 16) & 0xFF;
	color.y = (hex >> 8) & 0xFF;
	color.z = hex & 0xFF;
	return (color);
}

int				event_handler(int key_code, t_rtv *rtv)
{
	if ((key_code + 2) == 55)
	{
		ft_close(rtv);
		system("leaks RTv1");
		exit(0);
	}
	return (0);
}

void			ft_close(t_rtv *rtv)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	ft_putendl("Bey - bey!!! :(");
	free(rtv);
}