/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:00:59 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/20 15:51:58 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int keycode, t_map *map)
{
	int	x;
	int	y;

	x = map->player_x + ((keycode == 'd') - (keycode == 'a'));
	y = map->player_y + ((keycode == 's') - (keycode == 'w'));
	if (map->map[y][x] == '1' || (map->map[y][x] == 'E' && map->collectibles))
		return ;
	if (map->map[y][x] == 'C')
	{
		map->map[y][x] = '0';
		map->collectibles--;
	}
	if (map->map[y][x] == 'E' && !map->collectibles)
		exit_free(0, "you win!");
	mlx_put_image_to_window((game())->mlx, (game())->win, (game())->img[0], \
	x * 64, y * 64);
	mlx_put_image_to_window((game())->mlx, (game())->win, (game())->img[3], \
	map->player_x * 64, map->player_y * 64);
	map->player_x = x;
	map->player_y = y;
}
