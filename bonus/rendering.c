/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:01:57 by ychagri           #+#    #+#             */
/*   Updated: 2024/07/04 15:17:17 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	calcul(t_textures *texture, t_game *game)
{
	static int	i = 0;

	if (!(texture->frames % 7))
		texture->player = texture->player->next;
	if (!(texture->frames % 17))
		texture->coll = texture->coll->next;
	if (!(texture->frames % 13))
		texture->out_exit = texture->out_exit->next;
	if (!(texture->frames % 5))
	{
		i++;
		texture->enemy = texture->enemy->next;
		game->patrol = i > 5;
		if (i == 11)
			i = 0;
	}
}

void	put_img(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
		game->textures.floor, x * 80, y * 80);
	if (game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
			game->textures.out_exit->content, x * 80, y * 80);
	}
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
			game->textures.coll->content, x * 80, y * 80);
	else if (game->map[y][x] == 'e')
		mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
			game->textures.enemy->content, x * 80, y * 80);
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

void	norm(t_game *game)
{
	char	*number;

	mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
		game->textures.player->content,
		game->player.x * 80, game->player.y * 80);
	mlx_string_put(game->data.mlxptr, game->data.winptr,
		0, 0, 0xffffff, "MOVES->:");
	number = ft_itoa(game->moves);
	mlx_string_put(game->data.mlxptr, game->data.winptr,
		80, 0, 0xffffff, number);
	free(number);
	game->textures.frames++;
}

int	rendering(t_game *game)
{
	int		x;
	int		y;

	calcul(&game->textures, game);
	if (game->map[game->player.y][game->player.x] == 'e' && !game->patrol)
		return (ft_printf("\033[42m\t>>>>>YOU LOOSE!<<<<<\033[0m\n",
				game->moves), mlx_destroy_window(game->data.mlxptr,
				game->data.winptr), exit (0), 0);
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
	norm(game);
	return (0);
}
