/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:51:44 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/14 06:59:02 by ychagri          ###   ########.fr       */
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

t_coords	*x_y(char **map)
{
	int			i;
	int			k;
	t_coords	*player;

	if (!map || !*map)
		return (NULL);
	player = malloc (sizeof(t_coords *));
	if (!player)
		return (NULL);
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == 'P')
			{
				player->x = k;
				player->y = i;
			}
			k++;
		}
		i++;
	}
	return (player);
}

void	free_path(char **map, t_coords *player, t_coords *size)
{
	ft_putstr_fd("Error\nInvalid Path!!\n", 2);
	free_array(map);
	free(size);
	free(player);
	exit (1);
}

void	check_path(char **map)
{
	int			i;
	int			k;
	t_coords	*size;
	t_coords	*player;

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
				free_path(map, player, size);
			k++;
		}
		i++;
	}
}
