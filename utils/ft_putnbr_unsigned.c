/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:56:59 by fel-maac          #+#    #+#             */
/*   Updated: 2021/11/19 11:01:20 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int nb, int *printed)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10, printed);
		ft_putnbr_unsigned(nb % 10, printed);
	}
	else
		ft_putchar(nb + '0', printed);
}
