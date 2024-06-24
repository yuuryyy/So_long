/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssra <youssra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:04:48 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/19 16:12:31 by youssra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	fts1(char	**s1, char	*s2)
{
	*s1 = malloc(1);
	if (!*s1)
		return (1);
	*s1[0] = 0;
	if (!s2)
		return (1);
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = (char *)malloc(ft_strlen2(s1) + ft_strlen2(s2) + 1);
	if (!join)
		return (NULL);
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	if (s1)
		free(s1);
	join[i + j] = '\0';
	return (join);
}

int	ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if ((char)c == s[i])
		return (1);
	return (0);
}
//int main ()
//{
//	printf("%s",ft_strjoin("youssra", "chagri"));
//}