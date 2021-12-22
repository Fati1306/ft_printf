/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:04:32 by fel-maac          #+#    #+#             */
/*   Updated: 2021/11/20 07:44:47 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *printed);
void	ft_putstr(char *s, int *printed);
void	ft_putnbr(int n, int *printed);
void	ft_putnbr_address(unsigned long num, int *printed);
void	ft_putnbr_unsigned(unsigned int nb, int *printed);
void	ft_putnbr_hex(unsigned int num, int *printed, char *hex_base);

#endif