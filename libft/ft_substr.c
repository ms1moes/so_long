/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:37:57 by msimoes-          #+#    #+#             */
/*   Updated: 2022/02/22 15:37:57 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *src, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sl;
	char	*dest;

	if (src == NULL)
		return (NULL);
	i = -1;
	sl = ft_strlen(src);
	if (start >= sl)
	{
		dest = malloc(sizeof(char));
		if (dest == NULL)
			return (NULL);
		*dest = '\0';
		return (dest);
	}
	else if (sl < len)
		return (ft_strdup(src + start));
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (++i < len && start < sl)
		dest[i] = src[start + i];
	dest[i] = '\0';
	return (dest);
}
