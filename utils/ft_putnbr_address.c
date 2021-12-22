/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:57:52 by fel-maac          #+#    #+#             */
/*   Updated: 2021/11/20 10:15:13 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	while (s1[i])
		i++;
	dst = (char *)malloc(sizeof(char) * i + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	count_digits(unsigned long num)
{
	unsigned long	n;
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

static void	print_address(char *hex_num, int *printed)
{
	write(1, "0x", 2);
	*printed += 2;
	ft_putstr(hex_num, printed);
}

static void	print_hex_zero(int	*printed)
{
	write(1, "0x0", 3);
	*printed += 3;
}

void	ft_putnbr_address(unsigned long num, int *printed)
{
	char			*hex_num;
	int				len;
	unsigned long	rem;
	char			*hex_base;

	if (num == 0)
	{
		print_hex_zero(printed);
		return ;
	}
	hex_num = NULL;
	len = count_digits(num);
	hex_base = ft_strdup("0123456789abcdef");
	hex_num = (char *) malloc(sizeof(char) * len + 1 + 2);
	hex_num[len--] = '\0';
	while (num)
	{
		rem = num % 16;
		hex_num[len] = hex_base[rem];
		num /= 16;
		len--;
	}
	print_address(hex_num, printed);
	free(hex_num);
	free(hex_base);
}
