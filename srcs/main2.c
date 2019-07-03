/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:22:24 by ykaplien          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	main2(t_rtv *rtv)
{
	parse_scene(rtv);
	if (scene_check(rtv))
	{
		mlx_activities(rtv);
		//do it();
		
		mlx_activities_hooks(rtv);
	}
}

void	mlx_activities(t_rtv *rtv)
{
	rtv->endian = 0;
	rtv->size_line = WIN_X;
	rtv->d = 1;
	rtv->bpp = 32;
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, "RTv1 ykaplien");
	IMG_PTR = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
	rtv->img =
	mlx_get_data_addr(IMG_PTR, &rtv->bpp, &rtv->size_line, &rtv->endian);
}

void	mlx_activities_hooks(t_rtv *rtv)
{
	mlx_hook(WIN_PTR, 2, 5, event_handler, rtv);
	mlx_hook(WIN_PTR, 17, 1L << 17, closer, rtv);
	mlx_loop(MLX_PTR);	
}

int		scene_check(t_rtv *rtv)
{
	t_list	*src;

	src = rtv->obj;
	if (scene_check_add(src))
		return (1);
	else
		return (0);
}

int 	scene_check_add(t_list *src)
{
	if (src != NULL)
		return (1);
	else
		return (0);
}