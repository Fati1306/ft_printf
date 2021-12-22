/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:11:47 by fel-maac          #+#    #+#             */
/*   Updated: 2021/11/20 08:44:44 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *printed)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		*printed += 6;
		return ;
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
		*printed += i;
}
