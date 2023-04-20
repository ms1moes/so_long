/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:45:41 by msimoes-          #+#    #+#             */
/*   Updated: 2022/02/19 13:45:41 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*s;
	char	ch;

	i = 0;
	s = (char *)str;
	ch = (char)c;
	while (i < n)
	{
		if (s[i] == ch)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
