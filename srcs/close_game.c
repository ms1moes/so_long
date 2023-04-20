/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:26:40 by msimoes-          #+#    #+#             */
/*   Updated: 2023/01/13 12:26:40 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	close_game(void)
{
	int	i;

	i = 0;
	if (map()->map)
	{
		while (map()->map[i])
			free(map()->map[i++]);
		free(map()->map);
	}
	i = 0;
	if (game()->img)
	{
		while (game()->img[i])
			mlx_destroy_image(game()->mlx, game()->img[i++]);
		free(game()->img);
	}
	if (game()->win)
		mlx_destroy_window(game()->mlx, game()->win);
	if (game()->mlx)
	{
		mlx_destroy_display(game()->mlx);
		free(game()->mlx);
	}
	exit(0);
}

static void	free_tmp(void)
{
	int	i;

	i = 0;
	if (map()->tmp)
	{
		while (map()->tmp[i])
			free(map()->tmp[i++]);
		free(map()->tmp);
	}
}

void	exit_free(int error, char *str)
{
	if (error)
		ft_putstr_fd("Error: ", 2);
	ft_putstr_fd (str, 2);
	ft_putstr_fd ("\n", 2);
	free_tmp();
	close_game();
}
