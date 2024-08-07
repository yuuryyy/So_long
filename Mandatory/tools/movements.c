/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 04:29:33 by ychagri           #+#    #+#             */
/*   Updated: 2024/07/02 03:03:33 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	put_img(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
		game->textures.floor, x * 80, y * 80);
	if (game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
			game->textures.out_exit, x * 80, y * 80);
		if (game->colls > 0)
			mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
				game->textures.cage, x * 80, y * 80);
	}
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
			game->textures.coll, x * 80, y * 80);
	else if (game->map[y][x] == '1')
	{
		if (x % 2 == 0 || y + 1 % 2 == 0)
			mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
				game->textures.frame2, x * 80, y * 80);
		else
			mlx_put_image_to_window(game->data.mlxptr,
				game->data.winptr, game->textures.frame, x * 80, y * 80);
	}
}

int	rendering(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->data.mlxptr, game->data.winptr);
	y = 0;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			put_img(game, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
		game->textures.player, game->player.x * 80, game->player.y * 80);
	return (0);
}

void	move(t_game *game, int x, int y)
{
	char	c;

	c = game->map[y][x];
	if ((c == 'E' && game->colls != 0) || c == '1')
		return ;
	game->moves += 1;
	if (c == 'C')
		game->colls--;
	game->player.y = y;
	game->player.x = x;
	game->map[y][x] = '0';
	ft_printf("moves : %d\n", game->moves);
	if (c == 'E')
	{
		ft_printf("\033[42m\t<<<YOU WIN>>>\033[0m\n", game->moves);
		mlx_destroy_window(game->data.mlxptr, game->data.winptr);
		exit (0);
	}
}
