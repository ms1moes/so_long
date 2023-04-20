/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:35:57 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/20 15:51:17 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	static char	file[BUFFER_SIZE + 1];
	char		*line;
	int			digit;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FOPEN_MAX)
		return (NULL);
	line = 0;
	digit = 1;
	while (1)
	{
		if (!file[0])
			digit = read(fd, file, BUFFER_SIZE);
		if (digit > 0)
			line = ft_strjoin_gnl(line, file);
		if (ft_update_file(file) || digit < 1)
			break ;
	}
	return (line);
}
