/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:23:16 by msimoes-          #+#    #+#             */
/*   Updated: 2022/10/04 19:15:30 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, 800, 600, "so_long");	
	
	mlx_loop(mlx_ptr);
}

