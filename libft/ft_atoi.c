/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:02:53 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 20:49:53 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	unsigned long long int	res;
	int						flag;
	int						ind;

	res = 0;
	flag = 1;
	ind = 0;
	while ((str[ind] > 8 && str[ind] < 14) || str[ind] == 32)
		ind++;
	if (str[ind] == '-' || str[ind] == '+')
	{
		if (str[ind] == '-')
			flag = -1;
		ind++;
	}
	while (str[ind] >= '0' && str[ind] <= '9')
	{
		res = (res * 10) + (str[ind] - 48);
		ind++;
	}
	if (res > 9223372036854775807 && flag == -1)
		return (0);
	else if (res > 9223372036854775807)
		return (-1);
	return (res * flag);
}
