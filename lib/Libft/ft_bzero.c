/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:05:01 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/09 23:43:46 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *) str + i) = '\0';
		i++;
	}
	return (str);
}

//int	main()
//{
//	int	c[] = {500, 500};
//	int *b;
//	b = ft_bzero(c, 5);
//	printf("%d\n", b[0]);
//	printf("%d\n", b[1]);
//}