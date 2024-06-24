/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:19:08 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/15 01:25:23 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int nb, int *l, char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb <= 15)
	{
		ft_putchar(base[nb], l);
	}
	else
	{
		ft_puthex(nb / 16, l, c);
		ft_puthex(nb % 16, l, c);
	}
}

void	ft_hex(char x, unsigned int d, int *l)
{
	ft_puthex(d, l, x);
}
