/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:43:05 by msimoes-          #+#    #+#             */
/*   Updated: 2022/02/19 13:43:05 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && n > 0)
	{
		if (str1[i] != str2[i])
			break ;
		i++;
		n--;
	}
	if (str1[i] != str2[i] && n > 0)
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	else
		return (0);
}
