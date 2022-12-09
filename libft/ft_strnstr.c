/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:52:19 by msimoes-          #+#    #+#             */
/*   Updated: 2022/02/19 13:52:19 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*str2)
		return ((char *)str1);
	while (str1[i] != '\0' && i < n)
	{
		j = 0;
		while (str1[i + j] != '\0' && str1[i + j] == str2[j] && (i + j) < n
			&& str2[j] != '\0')
		{
			if (str2[j + 1] == '\0')
				return ((char *)&(str1[i]));
			j++;
		}
		i++;
	}
	return (0);
}
