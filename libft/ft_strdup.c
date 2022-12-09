/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:02:47 by msimoes-          #+#    #+#             */
/*   Updated: 2022/02/19 14:02:47 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	int		len;

	len = ft_strlen(str);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	ft_memmove(new, str, len);
	new[len] = '\0';
	return (new);
}
