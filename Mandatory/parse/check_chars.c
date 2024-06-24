/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssra <youssra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:07:35 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/22 14:58:23 by youssra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	check(char **map)
{
	int	i;
	int	k;

	if (!map || !*map)
	{
		ft_putstr_fd("\033[31mError\n", 2);
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
				ft_putstr_fd("\033[31mError\n\tInvalid Symbols!!\n", 2);
				free_array(map);
				exit (1);
			}
			k++;
		}
		i++;
	}
}

int	check_chars(char **map)
{
	if (!map || !*map)
	{
		ft_putstr_fd("\033[31mError\n", 2);
		exit (1);
	}
	check(map);
	return (1);
}

//t_coords	*mapsize(char **map)
//{
//	int			i;
//	int			k;
//	t_coords	*size;

//	if (!map || !*map)
//		return (NULL);
//	size = malloc (sizeof(t_coords *));
//	if (!size)
//		return (NULL);
//	i = 0;
//	while (map[i])
//	{
//		k = 0;
//		while (map[i][k])
//			k++;
//		i++;
//	}
//	size->x = k;
//	size->y = i;
//	return (size);
//}

void	path(char **map, t_coords size, int x, int y)
{
	if (x < 0 || x >= size.x || y < 0 || y >= size.y
		|| map[y][x] == '1' || map[y][x] == 'x')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = 'x';
	path(map, size, x - 1, y);
	path(map, size, x + 1, y);
	path(map, size, x, y - 1);
	path(map, size, x, y + 1);
}
