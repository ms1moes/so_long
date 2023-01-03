/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:25:31 by msimoes-          #+#    #+#             */
/*   Updated: 2023/01/03 17:35:08 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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