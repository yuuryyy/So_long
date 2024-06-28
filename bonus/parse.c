/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:09:26 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/28 12:09:44 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	element_check(char **map, char c, t_game *game)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == c)
			{
				if (c == 'P')
				{
					game->player.x = k;
					game->player.y = i;
				}
				count++;
			}
			k++;
		}
		i++;
	}
	return (count);
}

int	data_check(t_game *game)
{
	char	**map;

	map = game->map;
	if (!map || !*map || !game)
		return (ft_putstr_fd("\033[31mError\n", 2), exit (1), 0);
	if (element_check(map, 'P', game) != 1 || element_check(map, 'E', game) != 1
		|| element_check(map, 'C', game) < 1)
		return (
			ft_putstr_fd("\033[31mError\n\tInvalid number of a component!!\n",
				2), free_array(map), exit (1), 0);
	game->colls = element_check(map, 'C', game);
	return (1);
}

void	free_path(char **map, char **tmp)
{
	ft_putstr_fd("\033[31mError: Invalid Path!!\n", 2);
	free_array(map);
	free_array(tmp);
	exit (1);
}

void	check_path(t_game *game, char **tmp)
{
	int			i;
	int			k;

	if (!game ||!*tmp)
		return (free_array(tmp), exit(1));
	path(tmp, game->map_size, game->player.x, game->player.y);
	i = 0;
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k])
		{
			if (tmp[i][k] != 'x' && tmp[i][k] != '1' && tmp[i][k] != '0')
				free_path(game->map, tmp);
			k++;
		}
		i++;
	}
	free_array(tmp);
}
