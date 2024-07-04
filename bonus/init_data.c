/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:40:05 by ychagri           #+#    #+#             */
/*   Updated: 2024/07/04 13:45:29 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*protect_img(void *mlxptr, char *filename)
{
	int		k;
	void	*image;

	image = mlx_xpm_file_to_image(mlxptr, filename, &k, &k);
	if (!image)
		return (perror(filename), exit(1), NULL);
	return (image);
}

void	fill_list(char **str,t_game *game, t_list **lst)
{
	int	i;
	t_list	*node;

	i = 0;
	while (str[i])
	{
		node = ft_lstnew(protect_img(game->data.mlxptr,str[i]));
		ft_lstadd_back(lst,node );
		i++;
	}
	node->next = *lst;
}



void	init_textures(t_textures	*textures, void	*mlxptr, t_game *game)
{
	char *str[13] = {P1,P2,P3,P4, P5,P6,P7,P8,P9,P10,P11,P12 ,NULL};
	char	*coll[3] = {C1, C2, NULL};
	char	*exitat[5] = {E1, E2, E3, E4, NULL};
	char	*enemy[12] = {EN1,EN2,EN3,EN4, EN5,EN6,EN7,EN8,EN9, EN10,EN10, NULL};

	fill_list(str, game, &textures->player);
	fill_list(coll, game, &textures->coll);
	fill_list(exitat, game, &textures->out_exit);
	fill_list(enemy, game, &textures->enemy);
	textures->floor = protect_img(mlxptr, "textures/floor_b.xpm");
	textures->frame = protect_img(mlxptr, "textures/wall1_b.xpm");
	textures->frame2 = protect_img(mlxptr, "textures/wall2_b.xpm");
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
		if (i == 9)
			i = 0;
	}
}

int	rendering(t_game *game)
{
	int		x;
	int		y;
	char	*number;

	calcul(&game->textures, game);
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
	void	*img;
	img = game->textures.player->content;
	mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
		img, game->player.x * 80,game->player.y * 80);
	mlx_string_put(game->data.mlxptr, game->data.winptr,
		0, 0, 0xffffff, "MOVES->:");
	number = ft_itoa(game->moves);
	mlx_string_put(game->data.mlxptr, game->data.winptr,
		80, 0, 0xffffff, number);
	free(number);
	game->textures.frames++;
	return (0);
}

void	move(t_game *game, int x, int y)
{
	char	c;

	c = game->map[y][x];
	if ((c == 'E' && game->colls != 0) || c == '1')
		return ;
	else if (game->patrol == false && c == 'e')
	{
		ft_printf("\033[42m\t>>>>>YOU LOST!<<<<<\033[0m\n", game->moves);
		mlx_destroy_window(game->data.mlxptr, game->data.winptr);
		exit (0);
	}
	game->moves += 1;
	if (c == 'C')
		game->colls--;
	game->player.y = y;
	game->player.x = x;
	if (c == 'C')
		game->map[y][x] = '0';
	else if (c == 'E')
	{
		ft_printf("\033[42m\t<<<YOU WIN!>>>\033[0m\n", game->moves);
		mlx_destroy_window(game->data.mlxptr, game->data.winptr);
		exit (0);
	}
}
