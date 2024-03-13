/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:41:17 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/11 23:54:23 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

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

int	check_extension(char **av, int ac)
{
	int	i;
	

	if (!av || !*av || !ac)
		return (0);
	if (ac > 2 || count_words(av[1], ' ') > 1 || count_words(av[1], ' ') == 0)
		return (0);
	i = ft_strlen(av[1]) - 1;
	while (av[1][i] == ' ')
		i--;
	i = i - 4;
	if ((av[1][i] != ' ' && i > 0 )&& av[1][i + 1] == '.'
		&& av[1][i + 2] == 'b' && av[1][i + 3] == 'e' && av[1][i + 4] == 'r')
		return (1);
	else
		return (0);	
}
