/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:07:35 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/14 05:31:44 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

int	check_chars(char **map)
{
	int	i;
	int	k;
	
	if (!map || !*map)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] != '1' && map[i][k] != '0'
				&& map[i][k] != 'P' && map[i][k] != 'E' && map[i][k] != 'C')
				{
					ft_putstr_fd("Error\nInvalid Symbols!!\n", 2);
					free_array(map);
					exit (1);
				}
			k++;
		}
		i++;
	}
	return (1);
}
