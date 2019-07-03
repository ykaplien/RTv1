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

void	error(int error)
{
	if (error == 1)
		ft_putendl("Usage: ./RTv1 [filename]");
	else if (error == 2)
		ft_putendl("Can't open file, try another one or check filename!");
	else if (error == 3)
		ft_putendl("Not valid file!!!");
	exit(0);
}

int		is_num(char *string)
{
	int			ind;

	ind = 0;
	if (string)
	{
		if (string[ind] == '-')
			ind++;
		if (string[ind] == ' ')
			ind++;
		if (string[ind] == '\0')
			return (0);
		while (string[ind] >= '0' && string[ind] <= '9' && string[ind] != '\0')
			ind++;
		if (string[ind] == '\0')
			return (1);
	}
	return (0);
}

int			closer(t_rtv *rtv)
{
	ft_close(rtv);
	system("leaks RTv1");
	exit(0);
	return (0);
}

t_vector	vector_add(double x, double y, double z, double unknown)
{
	t_vector	new_vector;
	int			i;

	i = 0;
	new_vector.z = z;
	new_vector.y = y;
	new_vector.x = x;
	while (i <= 100)
		i++;
	new_vector.dot1 = unknown;
	new_vector.dot2 = unknown;
	return (new_vector);
}

int			rgb_to_hex(t_vector color)
{
	int		res;
	int		i;

	i = 0;
	while (i < 100)
		i++;
	res = color.x;
	res = (res << 8) + color.y;
	res = (res << 8) + color.z;
	return (res);
}
