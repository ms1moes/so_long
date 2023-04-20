/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:23:16 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/20 18:00:05 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checks(int y, int x)
{
	if (!check_map_closed(0))
		exit_free(1, "Map is not closed.");
	if (!check_map_chars(map()))
		exit_free(1, "Map has invalid characters.");
	map_tmp(0, 0);
	fill_path(map(), map()->player_x, map()->player_y);
	while (map()->tmp[y])
	{
		x = 0;
		while (map()->tmp[y][x])
		{
			if (map()->tmp[y][x] == 'C')
				exit_free(1, "Map has unreachable collectibles.");
			else if (map()->tmp[y][x] == 'E')
			{
				if (map()->tmp[y][x - 1] != 'P' && map()->tmp[y][x + 1] != 'P' \
				&& map()->tmp[y - 1][x] != 'P' && map()->tmp[y + 1][x] != 'P')
					exit_free(1, "Map has unreachable exit.");
			}
			x++;
		}
		y++;
	}
}

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		exit_free(1, "Invalid number of arguments.");
	if (check_ber(av[1]))
		exit_free(1, "Invalid .ber");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_free(1, "Invalid file.");
	(map())->map = map_reader(fd, NULL, 0);
	if (map()->map == NULL)
		exit_free(1, "empty map.");
	checks(0, 0);
	close(fd);
	(game())->mlx = mlx_init();
	(game())->win = mlx_new_window(game()->mlx, length(map()->map) * 64, \
	height(map()->map) * 64, "so_long");
	render_img();
	mlx_hook(game()->win, 2, 1L << 0, key_hook, map());
	mlx_hook(game()->win, 17, 1L << 2, close_hook, map());
	mlx_loop(game()->mlx);
}
