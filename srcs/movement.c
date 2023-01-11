/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:00:59 by msimoes-          #+#    #+#             */
/*   Updated: 2023/01/11 17:42:37 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    move_player(int keycode, t_map *map)
{
	int x;
	int y;
	
	printf("player_x: %d, player_y: %d\n", map->player_x, map->player_y);
	x = map->player_x + ((keycode == 'd') - (keycode == 'a'));
	y = map->player_y + ((keycode == 's') - (keycode == 'w'));
	printf("x: %d, y: %d\n", x, y);
	printf("map->collectibles: %i\n", map->collectibles);
	if (map->map[y][x] == '1' || (map->map[y][x] == 'E' && map->collectibles))
		return ;
	if (map->map[y][x] == 'C')
	{
		map->map[y][x] = '0';
		map->collectibles--;
	}
	if (map->map[y][x] == 'E' && !map->collectibles)
	{
		printf("You win!\n");
		exit(0);
	}
	mlx_put_image_to_window((game())->mlx, (game())->win, (game())->img[0], x * 64, y * 64);
	mlx_put_image_to_window((game())->mlx, (game())->win, (game())->img[3], \
	map->player_x * 64, map->player_y * 64);
	map->player_x = x;
	map->player_y = y;
}
