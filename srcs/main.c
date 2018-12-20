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
	char	*line;

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
	// printf("OK\n");
	// printf("%d\n", type);
	if (type == 1)
		parseSphere(rtv, line);
	else if (type == 2)
		parseCamera(rtv, line);
	else if (type == 3)
		parseCamera(rtv, line);

}


void	parseSphere(t_rtv *rtv, char *line)
{
	
}

void	parseCamera(t_rtv *rtv, char *line)
{
	int		dot[3];
	char	**data;

	data = ft_strsplit(&line[7], ',');
	dot[0] = ft_atoi(data[0]);
	dot[1] = ft_atoi(data[1]);
	dot[2] = ft_atoi(data[2]);
	printf("%d\n", dot[0]);
	printf("%d\n", dot[1]);
	printf("%d\n", dot[2]);
}

void	parseLight(t_rtv *rtv, char *line)
{

}

int		spotObject(char *line)
{
	int		type;
	char	**src;

	type = 0;
	src = ft_strsplit(line, ':');
	if (!(ft_strncmp(src[0], "sphere", 6)))
		type = 1;
	else if (!(ft_strncmp(src[0], "camera", 6)))
		type = 2;
	else if (!(ft_strncmp(src[0], "light", 5)))
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