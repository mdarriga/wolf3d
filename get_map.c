/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 16:06:30 by mdarriga          #+#    #+#             */
/*   Updated: 2015/01/20 13:43:35 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		print_error(void)
{
	ft_putendl("Map is invalid.");
	exit (0);
}

int			**ft_get_map(char *file, int i, int j, int **map)
{
	int		fd;
	char	**tmp;
	char	*line;

	if (!(map = (int **)malloc(sizeof(int *) * MAPW)))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error();
	while (get_next_line(fd, &line) > 0)
	{
		j = -1;
		tmp = ft_strsplit(line, ' ');
		if (!(map[i] = (int *)malloc(sizeof(int) * MAPW)))
			return (0);
		while (j++ < MAPW - 1)
			map[i][j] = ft_atoi(tmp[j]);
		i++;
	}
	close (fd);
	return (map);
}
