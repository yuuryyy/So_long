/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssra <youssra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:22:52 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/19 01:50:00 by youssra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			l = l + 1;
		i++;
	}
	return (l);
}

static int	count_chars(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	*ft_free(char **split, int i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
}

static char	**ftsplit2(char **s1, char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			s1[j] = (char *) malloc (sizeof(char) * count_chars(s + i, c) + 1);
			if (!s1[j])
				return (ft_free(s1, j));
			k = 0;
			while (s[i] != c && s[i])
				s1[j][k++] = s[i++];
			s1[j][k] = '\0';
			j++;
		}
	}
	s1[j] = 0;
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	char	**splite;
	size_t	len;

	if (!s)
		return (0);
	len = count_words((char *)s, c);
	splite = (char **)malloc (sizeof(char *) * (len + 1));
	if (!splite)
		return (NULL);
	splite = ftsplit2(splite, (char *)s, c);
	return (splite);
}
