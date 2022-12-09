/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:25:31 by msimoes-          #+#    #+#             */
/*   Updated: 2022/12/09 18:25:46 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char    **map_reader(int fd, char **map, int counter)
{
    char *line;

    line = get_next_line(fd);
    if (line)
        map = map_reader(fd, map, counter + 1);
    else
        map = malloc(sizeof(char *) * (counter + 1));
    if (!map)
        return (NULL);
    map[counter] = line;
    return (map);
}
