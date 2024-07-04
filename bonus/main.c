/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:06:39 by ychagri           #+#    #+#             */
/*   Updated: 2024/07/04 13:02:06 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	movement(int key, t_game *game)
{
	if (key == ESC)
	{
		mlx_destroy_window(game->data.mlxptr, game->data.winptr);
		exit(0);
	}
	else if (key == UP || key == W)
		move(game, game->player.x, game->player.y - 1);
	else if (key == A || key == LEFT)
		move(game, game->player.x - 1, game->player.y);
	else if (key == S || key == DOWN)
		move(game, game->player.x, game->player.y + 1);
	else if (key == D || key == RIGHT)
		move(game, game->player.x + 1, game->player.y);
	return (0);
}

int	close_win(t_game *game)
{
	(void) game;
	exit(0);
}

void	tqmira(char	**map)
{
	int	x;
	int	y;

	srand(time(NULL));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' && !(rand() % 23))
					map[y][x] = 'e';
			x++;
		}
		y++;
	}
}

void	f(){system("leaks so_long_b");}

int	main(int ac, char **av)
{
	t_game	game;

	atexit(f);
	ft_bzero(&game, sizeof(game));
	error_check(av, ac, &game);
	tqmira(game.map);
	game.map[game.player.y][game.player.x] = '0';
	game.data.mlxptr = mlx_init();
	if (!game.data.mlxptr)
		return (perror ("mlx_init\n"), 1);
	init_textures(&game.textures, game.data.mlxptr, &game);
	game.data.winptr = mlx_new_window(game.data.mlxptr, 80 * game.map_size.x,
			game.map_size.y * 80, "youssra_so_long");
	if (!game.data.winptr)
		return (1);
	mlx_loop_hook(game.data.mlxptr, rendering, &game);
	mlx_hook(game.data.winptr, 2, 0, movement, &game);
	mlx_hook(game.data.winptr, 17, 0, close_win, NULL);
	mlx_loop(game.data.mlxptr);
}
