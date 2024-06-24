/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:58:56 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/11 01:35:56 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	long long	i;
	int			sign;
	long long	res;
	long long	temp;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] == ' ') || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= (-1);
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		temp = res;
		res = res * 10 + (str[i++] - '0');
		if (temp != res / 10 && sign == 1)
			return (-1);
		else if (temp != res / 10 && sign == -1)
			return (0);
	}
	return (res * sign);
}
