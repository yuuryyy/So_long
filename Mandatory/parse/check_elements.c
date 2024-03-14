/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:51:44 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/14 05:43:28 by ychagri          ###   ########.fr       */
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
		while(map[i][k])
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
		||  element_check(map, 'C') < 1)
		{
			ft_putstr_fd("Error\nInvalid number of a component!!\n", 2);
			free_array(map);
			exit (1);
		}
	return (1);
}
p_coords	*x_y(char **map)
{
	int			i;
	int			k;
	p_coords	*player;

	if (!map || !*map)
		return (NULL);
	player = malloc (sizeof(p_coords *));
	if (!player)
		return (NULL);
	i = 0;
	while (map[i])
	{
		k = 0;
		while(map[i][k])
		{
			if (map[i][k] == 'P')
			{
					player->x = k;
					player->y = i;
					return (player);
			}
			k++;
		}
		i++;
	}
	return (NULL);
}
p_coords	*mapsize(char **map)
{
	int			i;
	int			k;
	p_coords	*size;

	if (!map || !*map)
		return (NULL);
	size = malloc (sizeof(p_coords *));
	if (!size)
		return (NULL);
	i = 0;
	while (map[i])
	{
		k = 0;
		while(map[i][k])
			k++;
		i++;
	}
	size->x = k;
	size->y = i;
	return (size);
}

void	path(char **map, p_coords *size,int x, int y)
{
	if (x < 0 || x >= size->x || y < 0 || y >= size->y
		|| map[y][x] == '1' || map[y][x] == 'x')
		return ;
	map[y][x] = 'x';
	path(map, size, x - 1,y);
	path(map, size, x+1,y);
	path(map, size,x,y-1);
	path(map, size, x,y + 1);
}

int	check_path(char **map)
{
	int	i;
	int	k;
	p_coords *size;
	p_coords *player;

	
	if (!map ||!*map)
		exit (1);
	size = mapsize(map);
	player = x_y(map);
	path(map, size, player->x, player->y);
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] != 'x' && map[i][k] != '1')
			{
				ft_putstr_fd("Error\nInvalid Path!!\n", 2);
				free_array(map);
				free(size);
				free(player);
				exit (1);
			}
			k++;
		}
		i++;
	}
	return (1);
}
