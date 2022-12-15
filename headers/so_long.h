/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:19:17 by msimoes-          #+#    #+#             */
/*   Updated: 2022/12/09 18:16:13 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**map;
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
	t_map	*map;
}	t_game;

#endif