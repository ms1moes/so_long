/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:26:26 by msimoes-          #+#    #+#             */
/*   Updated: 2023/01/11 17:20:21 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int key_hook(int keycode, void *param)
{
    t_map *map;

    map = (t_map *)param;
    if (keycode == 65307)
        exit (0);
    if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
        move_player(keycode, map);
    return (0);
}