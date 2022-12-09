/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:11:01 by msimoes-          #+#    #+#             */
/*   Updated: 2022/03/16 19:43:18 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(t_ui n, int i)
{
	if (n >= 10)
		i += ft_putunbr((n / 10), i);
	i += ft_putchar((n % 10) + '0');
	return (i);
}

int	ft_putp(t_llu n, int numdig)
{
	if (n > 15)
		numdig += ft_putp(n / 16, numdig);
	write(1, &HEXALOW[n % 16], 1);
	return (++numdig);
}

int	ft_puthexa_up(t_ui n, int numdig)
{
	if (n > 15)
		numdig += ft_puthexa_up(n / 16, numdig);
	write(1, &HEXAUP[n % 16], 1);
	return (++numdig);
}

int	ft_puthexa_low(t_ui n, int numdig)
{
	if (n > 15)
		numdig += ft_puthexa_low(n / 16, numdig);
	write(1, &HEXALOW[n % 16], 1);
	return (++numdig);
}
