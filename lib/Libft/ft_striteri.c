/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:02:31 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/08 21:15:18 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!f || !s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
//void	testt(unsigned int i, char *c )
//{
//	*c = *c + i;
//}

//int main()
//{
//	char str[]="abcd0";
//	ft_striteri(str, testt);
//	printf("%s",str);
//}