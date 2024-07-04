/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:40:05 by ychagri           #+#    #+#             */
/*   Updated: 2024/07/04 15:02:52 by ychagri          ###   ########.fr       */
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

void	fill_list(char **str, t_game *game, t_list **lst)
{
	int		i;
	t_list	*node;

	i = 0;
	while (str[i])
	{
		node = ft_lstnew(protect_img(game->data.mlxptr, str[i]));
		ft_lstadd_back(lst, node);
		i++;
	}
	node->next = *lst;
}

void	load_ex_en(t_game *game)
{
	char	*exitat[5];
	char	*enemy[12];

	exitat[0] = E1;
	exitat[1] = E2;
	exitat[2] = E3;
	exitat[3] = E4;
	exitat[4] = NULL;
	enemy[0] = EN1;
	enemy[1] = EN2;
	enemy[2] = EN3;
	enemy[3] = EN4;
	enemy[4] = EN5;
	enemy[5] = EN6;
	enemy[6] = EN7;
	enemy[7] = EN8;
	enemy[8] = EN9;
	enemy[9] = EN10;
	enemy[10] = EN10;
	enemy[11] = NULL;
	fill_list(exitat, game, &game->textures.out_exit);
	fill_list(enemy, game, &game->textures.enemy);
}

void	init_textures(t_textures	*textures, void	*mlxptr, t_game *game)
{
	char	*str[13];
	char	*coll[3];

	str[0] = P1;
	str[1] = P2;
	str[2] = P3;
	str[3] = P4;
	str[4] = P5;
	str[5] = P6;
	str[6] = P7;
	str[7] = P8;
	str[8] = P9;
	str[9] = P10;
	str[10] = P11;
	str[11] = P12;
	str[12] = NULL;
	coll[0] = C1;
	coll[1] = C2;
	coll[2] = NULL;
	fill_list(str, game, &textures->player);
	fill_list(coll, game, &textures->coll);
	load_ex_en(game);
	textures->floor = protect_img(mlxptr, "textures/floor_b.xpm");
	textures->frame = protect_img(mlxptr, "textures/wall1_b.xpm");
	textures->frame2 = protect_img(mlxptr, "textures/wall2_b.xpm");
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
	if (c == 'C')
		game->map[y][x] = '0';
	else if (c == 'E')
	{
		ft_printf("\033[42m\t<<<YOU WIN!>>>\033[0m\n", game->moves);
		mlx_destroy_window(game->data.mlxptr, game->data.winptr);
		exit (0);
	}
}
