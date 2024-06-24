/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:16:46 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/03 15:36:21 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	i;
	int	l;

	l = ft_strlen(s);
	i = l;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (s + i);
		i--;
	}
	return (0);
}
