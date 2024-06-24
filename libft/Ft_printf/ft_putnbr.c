/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:45:23 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/15 18:36:24 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *l)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-', l);
	}
	if (nbr <= 9)
	{
		nbr = nbr + '0';
		ft_putchar(nbr, l);
	}
	else
	{
		ft_putnbr(nbr / 10, l);
		ft_putnbr(nbr % 10, l);
	}
}
