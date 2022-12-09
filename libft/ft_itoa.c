/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:05:23 by msimoes-          #+#    #+#             */
/*   Updated: 2022/03/08 15:13:55 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_size(int n)
{
	if (n < 10 && n > -10)
		return (1);
	else
		return (1 + ft_size(n / 10));
}

char	*ft_itoa(int n)
{
	char	*new;
	int		size;

	size = ft_size(n) + (n < 0);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	new = (malloc(sizeof(char) * (size + 1)));
	if (new == NULL)
		return (NULL);
	new[size--] = '\0';
	if (n < 0)
	{
		new[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		new[0] = '0';
	while (n > 0)
	{
		new[size--] = n % 10 + 48;
		n = n / 10;
	}
	return (new);
}
