/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:56:56 by fel-maac          #+#    #+#             */
/*   Updated: 2021/11/20 10:12:12 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int num)
{
	unsigned int	n;
	int				len;

	n = num;
	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	print_zero(int	*printed)
{
	write(1, "0", 1);
	*printed += 1;
}

void	ft_putnbr_hex(unsigned int num, int *printed, char *hex_base)
{
	char	*hex_num;
	int		len;
	int		rem;

	if (num == 0)
	{
		print_zero(printed);
		return ;
	}
	hex_num = NULL;
	len = count_digits(num);
	rem = 0;
	hex_num = (char *) malloc(sizeof(char) * len + 1);
	hex_num[len] = '\0';
	len--;
	while (num)
	{
		rem = num % 16;
		hex_num[len] = hex_base[rem];
		num /= 16;
		len--;
	}
	ft_putstr(hex_num, printed);
	free(hex_num);
}
