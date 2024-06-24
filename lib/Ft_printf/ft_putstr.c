/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:52:32 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/11 01:36:54 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *l)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", l);
		return ;
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i], l);
			i++;
		}
	}
}
	//int main()
	//{
	//	char a = '3';
	//	char	*p;
	//	p = &a;
	//	ft_putstr(p);
	//}
