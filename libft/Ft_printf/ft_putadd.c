/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:05:30 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/17 14:40:50 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrhp(unsigned long int nb, int *l)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb <= 15)
	{
		ft_putchar(base[nb], l);
	}
	else
	{
		ft_putnbrhp(nb / 16, l);
		ft_putnbrhp(nb % 16, l);
	}
}

void	putadd(void *d, int *l)
{
	unsigned long int	nb;

	nb = (unsigned long int)d;
	ft_putstr("0x", l);
	ft_putnbrhp(nb, l);
}
//int main()
//{
//	int c=9;
//	int	*p=&c;

//	putadd((unsigned long int)p,&c);
//	printf("\n%p",p);
//}
