/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:31:36 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/20 15:51:11 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = -1;
	ptr = malloc(sizeof(char) * ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!ptr)
		return (NULL);
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		ptr[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	ptr[i] = '\0';
	if (s1)
		free(s1);
	return (ptr);
}

int	ft_update_file(char *buffer)
{
	int		i;
	int		j;
	int		is_nl;

	i = -1;
	is_nl = 0;
	j = 0;
	while (buffer[++i])
	{
		if (is_nl)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			is_nl = 1;
		buffer[i] = 0;
	}
	return (is_nl);
}
