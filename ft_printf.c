/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:06:04 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/22 11:07:30 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_hex(char c, va_list p, int *printed)
{
	if (c == 'x')
		ft_putnbr_hex(va_arg(p, int), printed, "0123456789abcdef");
	else
		ft_putnbr_hex(va_arg(p, int), printed, "0123456789ABCDEF");
}

static void	check_format(const char *format, va_list p, int *printed, int i)
{
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i] == 'c')
				ft_putchar(va_arg(p, int), printed);
			else if (format[i] == 's')
				ft_putstr(va_arg(p, char *), printed);
			else if (format[i] == 'p')
				ft_putnbr_address((unsigned long)(va_arg(p, void *)), printed);
			else if (format[i] == 'i' || format[i] == 'd')
				ft_putnbr(va_arg(p, int), printed);
			else if (format[i] == 'u')
				ft_putnbr_unsigned(va_arg(p, int), printed);
			else if (format[i] == 'x' || format[i] == 'X')
				check_hex(format[i], p, printed);
			else if (format[i] == '%')
				ft_putchar('%', printed);
			else if (format[i] == '\0')
				return ;
			else
				ft_putchar(format[i], printed);
		}
		else
			ft_putchar(format[i], printed);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	p;
	int		printed;

	i = 0;
	printed = 0;
	va_start(p, format);
	check_format(format, p, &printed, i);
	va_end(p);
	return (printed);
}
