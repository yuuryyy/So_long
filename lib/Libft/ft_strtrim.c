/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:02:30 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/05 19:21:51 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*trim;

	start = 0;
	if (!s1 || !set)
		return (0);
	end = ft_strlen((char *)s1);
	while (s1[start] != '\0' && checker(set, s1[start]))
		start++;
	while (end > start && checker(set, s1[end - 1]))
		end--;
	len = end - start;
	trim = ft_substr(s1, start, len);
	return (trim);
}
