/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:53 by msimoes-          #+#    #+#             */
/*   Updated: 2023/01/03 18:12:54 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	load_img()
{
	int i;

	i = 64;
	game()->img = malloc(9 * sizeof(void *));
	game()->img[0] = mlx_xpm_file_to_image(game()->mlx, "assets/player.xpm", &i, &i);
	game()->img[1] = mlx_xpm_file_to_image(game()->mlx, "assets/collectable.xpm", &i, &i);
	game()->img[2] = mlx_xpm_file_to_image(game()->mlx, "assets/wall.xpm", &i, &i);
	game()->img[3] = mlx_xpm_file_to_image(game()->mlx, "assets/floor.xpm", &i, &i);
	game()->img[4] = mlx_xpm_file_to_image(game()->mlx, "assets/exit_front.xpm", &i, &i);
	game()->img[5] = mlx_xpm_file_to_image(game()->mlx, "assets/exit_mid.xpm", &i, &i);
	game()->img[6] = mlx_xpm_file_to_image(game()->mlx, "assets/exit_mid2.xpm", &i, &i);
	game()->img[7] = mlx_xpm_file_to_image(game()->mlx, "assets/exit_side.xpm", &i, &i);
	game()->img[8] = NULL;
} 

void render_img()
{
	int y;
	int x;

	load_img();
	y = -1;
	while (map()->map[++y])
	{
		x = -1;
		while (map()->map[y][++x])
		{
			if (map()->map[y][x] == '1')
				mlx_put_image_to_window(game()->mlx, game()->win, game()->img[2], x * 64, y * 64);
			else if (map()->map[y][x] == '0')
				mlx_put_image_to_window(game()->mlx, game()->win, game()->img[3], x * 64, y * 64);
			else if (map()->map[y][x] == 'C')
				mlx_put_image_to_window(game()->mlx, game()->win, game()->img[1], x * 64, y * 64);
			else if (map()->map[y][x] == 'E')
				mlx_put_image_to_window(game()->mlx, game()->win, game()->img[4], x * 64, y * 64);
			else if (map()->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game()->mlx, game()->win, game()->img[0], x * 64, y * 64);
				map()->player_x = y * 64;
				map()->player_y = x * 64;
			}
		}
	}
}