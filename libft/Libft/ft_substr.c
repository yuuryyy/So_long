/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:19:23 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/10 17:45:59 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen(((char *)s) + start))
		len = ft_strlen((char *)s) - start;
	sub = (char *) malloc (len * sizeof(char) + 1);
	if (!sub)
		return (0);
	while (s[i] && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
//int main()
//{
//	char str[]="aaayuuryyyy";
//	char *sub;
//	sub = ft_substr(str,100,7);
//	printf("%s\n",sub);
//}