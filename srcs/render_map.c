/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:53 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/20 15:52:03 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(void)
{
	int	i;

	i = 64;
	(game())->img = malloc(6 * sizeof(void *));
	if (!(game())->img)
		exit_free(1, "Error: malloc failed.");
	(game())->img[0] = mlx_xpm_file_to_image((game())->mlx, \
	"assets/player.xpm", &i, &i);
	(game())->img[1] = mlx_xpm_file_to_image((game())->mlx, \
	"assets/collectable.xpm", &i, &i);
	(game())->img[2] = mlx_xpm_file_to_image((game())->mlx, \
	"assets/wall.xpm", &i, &i);
	(game())->img[3] = mlx_xpm_file_to_image((game())->mlx, \
	"assets/floor.xpm", &i, &i);
	(game())->img[4] = mlx_xpm_file_to_image((game())->mlx, \
	"assets/exit_front.xpm", &i, &i);
	(game())->img[5] = NULL;
}

void	render_img(void)
{
	int	y;
	int	x;

	load_img();
	y = -1;
	while (map()->map[++y])
	{
		x = -1;
		while (map()->map[y][++x])
		{
			if (map()->map[y][x] == '1')
				mlx_put_image_to_window(game()->mlx, \
				game()->win, game()->img[2], x * 64, y * 64);
			else if (map()->map[y][x] == '0')
				mlx_put_image_to_window(game()->mlx, \
				game()->win, game()->img[3], x * 64, y * 64);
			else if (map()->map[y][x] == 'C')
			{
				mlx_put_image_to_window(game()->mlx, \
				game()->win, game()->img[1], x * 64, y * 64);
			}
		}
	}
	render_img2();
}

void	render_img2(void)
{
	int	y;
	int	x;

	y = -1;
	while (map()->map[++y])
	{
		x = -1;
		while (map()->map[y][++x])
		{
			if (map()->map[y][x] == 'E')
				mlx_put_image_to_window(game()->mlx, game()->win, \
				game()->img[4], x * 64, y * 64);
			else if (map()->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game()->mlx, game()->win, \
				game()->img[0], x * 64, y * 64);
				map()->player_x = x;
				map()->player_y = y;
			}
		}
	}
}
