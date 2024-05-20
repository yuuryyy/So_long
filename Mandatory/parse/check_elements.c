/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:51:44 by ychagri           #+#    #+#             */
/*   Updated: 2024/04/06 21:02:41 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

int	element_check(char **map, char c)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	count = 0;
	if (!map || !*map)
		return (0);
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == c)
				count++;
			k++;
		}
		i++;
	}
	return (count);
}

int	data_check(char **map)
{
	if (!map || !*map)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	if (element_check(map, 'P') != 1 || element_check(map, 'E') != 1
		|| element_check(map, 'C') < 1)
	{
		ft_putstr_fd("Error\nInvalid number of a component!!\n", 2);
		free_array(map);
		exit (1);
	}
	return (1);
}

t_coords	x_y(char **map)
{
	t_coords	coords;
	int			x;
	int			y;

	coords.x = -1;
	coords.y = -1;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				coords.x = x;
				coords.y = y;
				return (coords);
			}
			x++;
		}
		y++;
	}
	return (coords);
}

void	free_path(char **map, char **tmp)
{
	ft_putstr_fd("Error\nInvalid Path!!\n", 2);
	free_array(map);
	free_array(tmp);
	exit (1);
}

void	check_path(char **tmp,char **map,t_coords size,t_coords player)
{
	int			i;
	int			k;

	if (!map ||!*map)
		return ;
	path(map, size, player.x, player.y);
	//printf("%d   %d\n", size.x, size.y);
	//printf("%d   %d\n", player.x, player.y);
	//printf("%s\n", map[1]);
	//printf("%s\n", map[2]);
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] != 'x' && map[i][k] != '1')
				free_path(map, tmp);
			k++;
		}
		i++;
	}
	
}
