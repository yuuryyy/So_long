/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:40:05 by ychagri           #+#    #+#             */
/*   Updated: 2024/07/01 06:54:06 by ychagri          ###   ########.fr       */
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

void	fill_list(void	**pics, t_game	*game, int flag)
{
	int	i;
	t_list	*head;
	t_list	*node;

	i = 0;
	head = ft_lstnew(pics[i--]);
	while (i < 4)
	{
		node = ft_lstnew(pics[i]);
		ft_lstadd_back(&head, node);
		node->next = NULL;
		free(node);
		i++;
	}
	node = ft_lstlast(head);
	node->next = head;
	if (flag == LEFT)
		game->textures.l_player = head;
	else
		game->textures.r_player = head;
}

void	init_textures(t_textures	*textures, void	*mlxptr, t_game *game)
{
	void	*leftp[5];
	void	*rightp[5];

	leftp[0] = protect_img(mlxptr, LEFT1);
	leftp[1] = protect_img(mlxptr, LEFT2);
	leftp[2] = protect_img(mlxptr, LEFT3);
	leftp[3] = protect_img(mlxptr, LEFT3);
	leftp[4] = NULL;
	rightp[0] = protect_img(mlxptr, RIGHT1);
	rightp[1] = protect_img(mlxptr, RIGHT2);
	rightp[2] = protect_img(mlxptr, RIGHT3);
	rightp[3] = protect_img(mlxptr, RIGHT4);
	rightp[4] = NULL;
	fill_list(leftp,game, LEFT);
	fill_list(rightp,game, RIGHT);
	textures->floor = protect_img(mlxptr, "textures/floor.xpm");
	textures->frame = protect_img(mlxptr, "textures/frames.xpm");
	textures->frame2 = protect_img(mlxptr, "textures/frames2.xpm");
	textures->coll = protect_img(mlxptr, "textures/colls.xpm");
	textures->out_exit = protect_img(mlxptr, "textures/exit.xpm");
	textures->cage = protect_img(mlxptr, "textures/cage.xpm");
}

// void	put_img(t_game *game, int x, int y)
// {
// 	mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
// 		game->textures.floor, x * 80, y * 80);
// 	if (game->map[y][x] == 'E')
// 	{
// 		mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
// 			game->textures.out_exit, x * 80, y * 80);
// 		if (game->colls > 0)
// 			mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
// 				game->textures.cage, x * 80, y * 80);
// 	}
// 	else if (game->map[y][x] == 'C')
// 		mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
// 			game->textures.coll, x * 80, y * 80);
// 	else if (game->map[y][x] == '1')
// 	{
// 		if (x % 2 == 0 || y + 1 % 2 == 0)
// 			mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
// 				game->textures.frame2, x * 80, y * 80);
// 		else
// 			mlx_put_image_to_window(game->data.mlxptr,
// 				game->data.winptr, game->textures.frame, x * 80, y * 80);
// 	}
// }

// int	rendering(t_game *game)
// {
// 	int		x;
// 	int		y;
// 	char	*number;

// 	mlx_clear_window(game->data.mlxptr, game->data.winptr);
// 	y = 0;
// 	while (y < game->map_size.y)
// 	{
// 		x = 0;
// 		while (x < game->map_size.x)
// 		{
// 			put_img(game, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(game->data.mlxptr, game->data.winptr,
// 		game->textures.player, game->player.x * 80, game->player.y * 80);
// 	mlx_string_put(game->data.mlxptr, game->data.winptr,
// 		0, 0, 0x800080, "MOVES->:");
// 	number = ft_itoa(game->moves);
// 	mlx_string_put(game->data.mlxptr, game->data.winptr,
// 		80, 0, 0x800080, number);
// 	free(number);
// 	return (0);
// }

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
	if (c == 'E')
	{
		ft_printf("\033[42m\t<<<YOU WIN>>>\033[0m\n", game->moves);
		mlx_destroy_window(game->data.mlxptr, game->data.winptr);
		exit (0);
	}
}
