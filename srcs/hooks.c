/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:26:26 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/20 16:50:59 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keycode == 65307)
		exit_free(0, "Game closed.");
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		move_player(keycode, map);
	return (0);
}

int	close_hook(void)
{
	exit_free(0, "Game closed.");
	return (0);
}
