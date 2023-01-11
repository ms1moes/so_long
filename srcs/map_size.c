/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:40:11 by msimoes-          #+#    #+#             */
/*   Updated: 2023/01/11 15:54:49 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	length(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] && map[0][i] != '\n')
		i++;
	return (i);
}

int	height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
