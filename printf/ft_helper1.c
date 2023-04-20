/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:26:26 by msimoes-          #+#    #+#             */
/*   Updated: 2022/03/14 16:29:41 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

static int	ft_putnbr(int n, int i)
{
	if (n > 9 || n < -9)
		i += ft_putnbr(n / 10, i);
	write(1, &DEC[n % 10 * ((n > 0) - (n < 0))], 1);
	return (++i);
}

int	ft_writenbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		ft_putchar('-');
	return ((n < 0) + ft_putnbr(n, i));
}
