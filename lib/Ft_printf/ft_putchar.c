/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:43:32 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/17 16:30:14 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *l)
{
	write (1, &c, 1);
	*l = *l + 1;
}
//int main()
//{
//	int l;
//	l = 0;
//	ft_putchar('a', &l);
//	printf("l = %d\n", l);
//	ft_putchar('b', &l);
//	printf("l = %d\n", l);
//	return (0);
//}
