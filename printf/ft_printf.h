/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:22:14 by msimoes-          #+#    #+#             */
/*   Updated: 2022/03/14 16:16:20 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEXALOW 	"0123456789abcdef"
# define HEXAUP 	"0123456789ABCDEF"
# define DEC 		"0123456789"

typedef unsigned long long	t_llu;
typedef unsigned int		t_ui;

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_writenbr(int n);
int		ft_putunbr(t_ui n, int i);
int		ft_putp(t_llu n, int numdig);
int		ft_puthexa_low(t_ui n, int numdig);
int		ft_puthexa_up(t_ui n, int numdig);

#endif