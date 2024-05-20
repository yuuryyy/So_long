/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 04:17:26 by ychagri           #+#    #+#             */
/*   Updated: 2024/04/06 22:33:15 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

t_coords	size_map(char **map)
{
	int			y;

	y = 0;
	while (map[y])
		y++;
	return ((t_coords){ft_strlen(map[0]), y});	
}

void	error_check(char **av, int ac, t_game *game)
{
	char	*file;
	char	**map;
	char	**tmp;
	int		y;
	int		x;

	if (!av || !*av)
		return ;
	check_extension(av, ac);
	file = filename(av);
	map = get_map(file);
	walls_check(map);
	data_check(map);
	check_chars(map);
	game->map_size = size_map(map);
	game->player = x_y(map);
	y = 0;
	tmp = malloc ((game->map_size.y + 1) * sizeof(char *));
	if (!tmp)
	while (map[y])
	{
		x = 0;
		tmp[y] = malloc(game->map_size.x + 1);
		if (!tmp[y])
		{
			ft_putstr_fd("Error\nmalloc failed!", 2);
			ft_free(tmp, y);
			free_array(map);
			exit(1);
		}
			return;//free
		while (map[y][x])
		{
			tmp[y][x] = map[y][x];
			x++;
		}
		tmp[y][x] = '\0';
		y++;
	}
	tmp[y] = 0;
	check_path(map, tmp, game->map_size, game->player);
	free_array(tmp);
	game->map = map;
	// free_array(game->map);
}
