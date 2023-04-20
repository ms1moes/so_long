/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:25:56 by msimoes-          #+#    #+#             */
/*   Updated: 2022/02/22 19:25:56 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	a;
	size_t	b;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	a = 0;
	b = ft_strlen(s1);
	while (ft_strchr(set, s1[a]) && s1[a])
		a++;
	while (ft_strrchr(set, *(s1 + b - 1)) && b > a)
		b--;
	new = ft_substr(s1, a, b - a);
	return (new);
}
