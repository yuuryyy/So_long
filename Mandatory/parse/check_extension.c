/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssra <youssra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:41:17 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/22 14:59:12 by youssra          ###   ########.fr       */
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
	if (ac != 2 || count_words(av[1], ' ') > 1 || count_words(av[1], ' ') == 0)
		return (ft_putstr_fd("\033[31mError\n\tInvalid arguments !!\n", 2),
			ft_putstr_fd("\033[36mExample:\n\t./so_long <filename>.ber\n", 2),
			exit(1), 0);
	i = ft_strlen(av[1]) - 1;
	while (av[1][i] == ' ')
		i--;
	i = i - 4;
	if ((av[1][i] != ' ' && i > 0) && av[1][i + 1] == '.'
		&& av[1][i + 2] == 'b' && av[1][i + 3] == 'e' && av[1][i + 4] == 'r')
		return (1);
	else
	{
		ft_putstr_fd("\033[31mError\n\tInvalid filename!!\n", 2);
		ft_putstr_fd("\033[36mExample:\n\t./so_long <filename>.ber\n", 2);
		exit (1);
	}
}
