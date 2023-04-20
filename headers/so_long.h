/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:19:17 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/20 16:49:38 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**map;
	char	**tmp;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exit;
	int		player;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	**img;
}	t_game;

//struct calls
t_map	*map(void);
t_game	*game(void);

//map size
int		height(char **map);
int		length(char **map);

//map checks
int		check_ber(char *str);
int		check_map_closed(int i);
int		check_map_chars(t_map *map);

char	**map_reader(int fd, char **map, int counter);
void	render_img(void);
void	render_img2(void);
int		key_hook(int keycode, void *param);
int		close_hook();
void	move_player(int keycode, t_map *map);
void	map_tmp(int x, int y);
void	fill_path(t_map *map, int x, int y);

//free and exit
void	exit_free(int error, char *str);

#endif