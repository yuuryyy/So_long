/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssra <youssra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:00:48 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/22 15:01:05 by youssra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

char	*filename(char **av)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	while (av[1][i] == ' ' && av[1][i])
		i++;
	k = i;
	while (av[1][k] != ' ' && av[1][k])
		k++;
	str = malloc (k - i + 1);
	if (!str)
	{
		ft_putstr_fd("\033[31mError\n\tmalloc failed \n", 2);
		exit (1);
	}
	k = 0;
	while (av[1][i] != ' ' && av[1][i])
	{
		str[k++] = av[1][i];
		i++;
	}
	str[k] = '\0';
	return (str);
}
