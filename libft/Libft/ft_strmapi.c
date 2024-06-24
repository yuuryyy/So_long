/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:30:02 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/11 20:28:06 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s)
		return (0);
	res = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
//char	testt(unsigned int i, char c )
//{
//	c = c + i;
//	return	(c);
//}
//int main()
//{
//	printf("%s\n", ft_strmapi("abcd0 ", testt));
//}