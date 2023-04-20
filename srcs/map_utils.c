/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:25:31 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/20 17:53:17 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_reader(int fd, char **map, int i)
{
	char	*str;

	str = get_next_line(fd);
	if (str)
		map = map_reader(fd, map, i + 1);
	if (!map && i != 0)
		map = malloc((i + 1) * sizeof(char *));
	if (!map)
		return (0);
	map[i] = str;
	return (map);
}

void	map_tmp(int j, int i)
{
	map()->tmp = malloc((map()->map_height + 1) * sizeof(char *));
	if (!map()->tmp)
		return ;
	while (map()->map[j])
	{
		i = 0;
		map()->tmp[j] = malloc((map()->map_width + 2) * sizeof(char));
		while (map()->map[j][i])
		{
			map()->tmp[j][i] = map()->map[j][i];
			i++;
		}
		map()->tmp[j][i] = 0;
		j++;
	}
	map()->tmp[j] = 0;
}
