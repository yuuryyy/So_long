/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:00:48 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/12 00:07:12 by ychagri          ###   ########.fr       */
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
		return (NULL);
	k = 0;
	while (av[1][i] != ' ' && av[1][i])
	{
		str[k] = av[1][i];
		k++;
		i++;
	}
	str[k] ='\0';
	return (str);
}