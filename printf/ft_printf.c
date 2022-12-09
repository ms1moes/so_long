/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:14:30 by msimoes-          #+#    #+#             */
/*   Updated: 2022/03/16 14:33:01 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	argtype(va_list ap, const char *str, int i)
{
	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (str[i + 1] == 'p')
		return (ft_putstr("0x") + ft_putp(va_arg(ap, t_llu), 0));
	else if ((str[i + 1] == 'i') || (str[i + 1] == 'd'))
		return (ft_writenbr(va_arg(ap, int)));
	else if (str[i + 1] == 'u')
		return (ft_putunbr(va_arg(ap, t_ui), 0));
	else if (str[i + 1] == 'x')
		return (ft_puthexa_low(va_arg(ap, t_ui), 0));
	else if (str[i + 1] == 'X')
		return (ft_puthexa_up(va_arg(ap, t_ui), 0));
	else if (str[i + 1] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += (argtype(ap, str, i));
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
