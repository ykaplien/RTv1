/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:04:09 by ykaplien          #+#    #+#             */
/*   Updated: 2018/10/25 15:04:10 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv.h"

void	error(int error)
{
	if (error == 1)
		ft_putendl("Usage: ./RTv1 [fileaname]");
	exit(0);
}

void	parseScene(t_rtv *rtv, char* mapName)
{
	int		fd;
	char*	line;

	fd = open(mapName, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("No such file ");
		ft_putendl(mapName);
	}
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			parseLine(rtv, line);
			rtv->figuresCount++;
			free(line);
		}
	}
}

void	parseLine(t_rtv *rtv, char *line)
{
	int		type;

	type = spotObject(line);
	
}

int		spotObject(char *line)
{
	int		type;

	type = 0;
	if (!(ft_strncmp(line, "sphere", 6)))
		type = 1;
	else if (!(ft_strncmp(line, "camera", 6)))
		type = 2;
	else if (!(ft_strncmp(line, "light", 6)))
		type = 3;
	return (type);
}

int		main(int argc, char **argv)
{
	t_rtv	*rtv;

	if (argc != 2)
		error(1);
	else
	{
		rtv = (t_rtv*)ft_memalloc(sizeof(t_rtv));
		parseScene(rtv, argv[1]);
	}
	return (0);
}