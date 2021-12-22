/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:21:58 by fel-maac          #+#    #+#             */
/*   Updated: 2021/11/20 09:00:03 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *printed)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*printed += 11;
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		ft_putchar('-', printed);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, printed);
		ft_putnbr(n % 10, printed);
	}
	else
		ft_putchar(n + '0', printed);
}
