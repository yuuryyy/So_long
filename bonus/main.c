/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:06:39 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/28 13:35:04 by ychagri          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game	game;

	error_check(av, ac, &game);
	game.map[game.player.y][game.player.x] = '0';
	game.data.mlxptr = mlx_init();
	if (!game.data.mlxptr)
		return (perror ("mlx_init\n"), 1);
	init_textures(&game.textures, game.data.mlxptr);
	game.data.winptr = mlx_new_window(game.data.mlxptr, 80 * game.map_size.x,
			game.map_size.y * 80, "youssra_so_long");
	if (!game.data.winptr)
		return (1);
	mlx_loop_hook(game.data.mlxptr, rendering, &game);
	mlx_hook(game.data.winptr, 2, 0, movement, &game);
	mlx_hook(game.data.winptr, 17, 0, close_win, NULL);
	mlx_loop(game.data.mlxptr);
}
