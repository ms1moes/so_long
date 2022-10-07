/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:35:57 by msimoes-          #+#    #+#             */
/*   Updated: 2022/10/04 18:49:04 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

char	*get_next_line(int fd)
{
	static char	file[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			digit;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FOPEN_MAX)
		return (NULL);
	line = 0;
	digit = 1;
	while (1)
	{
		if (!file[fd][0])
			digit = read(fd, file[fd], BUFFER_SIZE);
		if (digit > 0)
			line = ft_strjoin_gnl(line, file[fd]);
		if (ft_update_file(file[fd]) || digit < 1)
			break ;
	}
	return (line);
}
