/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:51:48 by vkarpova          #+#    #+#             */
/*   Updated: 2019/02/01 17:51:49 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double		scalar_product(t_vector x, t_vector y)	//dot
{
	t_vector	result;

	result.x = x.x * y.x;
	result.y = x.y * y.y;
	result.z = x.z * y.z;
	result.result = result.x + result.y + result.z;
	return (result.result);
}

t_vector		vec_normalization(t_vector source)
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

t_vector		vec_minus(t_vector f, t_vector s)
{
	t_vector	result;

	result.x = f.x - s.x;
	result.y = f.y - s.y;
	result.z = f.z - s.z;
	return (result);
}

t_vector		vec_plus(t_vector f, t_vector s)	
{
	t_vector	result;

	result.x = f.x + s.x;
	result.y = f.y + s.y;
	result.z = f.z + s.z;
	return (result);
}

t_vector		vec_mult(t_vector f, double mult)	// times
{
	t_vector	result;

	result.x = f.x * mult;
	result.y = f.y * mult;
	result.z = f.z * mult;
	return (result);
}