/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:23:16 by msimoes-          #+#    #+#             */
/*   Updated: 2023/01/11 17:50:22 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	checks(void)
{
	if (!check_map_chars(map()))
		exit(0);
	if (!check_map_closed(0))
		exit(0);
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
		return (0);
	if (check_ber(av[1]))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	(map())->map = map_reader(fd, NULL, 0);
	if (map()->map == NULL)
		return (0);
	checks();
	close(fd);
	(game())->mlx = mlx_init();
	(game())->win = mlx_new_window(game()->mlx, length(map()->map) * 64, \
	height(map()->map) * 64, "so_long");
	render_img();
	mlx_key_hook(game()->win, key_hook, map());
	mlx_loop(game()->mlx);
}
