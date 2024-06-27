/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:46:30 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/27 08:17:39 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inc/so_long.h"

void	f(){system("leaks so_long");}

// #define namethem  ./textures/player.xpm
// #define namethem ./textures/player.xpm
// #define namethem ./textures/player.xpm
// #define namethem ./textures/player.xpm
// #define namethem ./textures/player.xpm
// #define namethem ./textures/player.xpm
// #define namethem ./textures/player.xpm

typedef enum t_num{
	W = 13,
	UP = 126,
	A = 0,
	LEFT = 123,
	S = 1,
	DOWN = 125,
	D = 2,
	RIGHT = 124,
	ESC = 53
}	moves;

int	movement(int key, t_game *game)
{
	if (key == ESC)
	{
		mlx_destroy_window(game->data.mlxptr, game->data.winptr);
		exit (0);
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
	exit (0);
}

void	*img(void *mlxptr, char *filename)
{
	int		k;
	void	*image;

	image =  mlx_xpm_file_to_image(mlxptr, filename, &k, &k);
	if (!image)
		return (perror(filename), exit (1), NULL);
	return (image);
}

void	*textures(t_textures	*textures, void	*mlxptr)
{
	textures->player = img(mlxptr, "textures/player.xpm");
	if (!textures->player)
		return (perror("textures/player.xpm"), NULL);	
	textures->floor = img(mlxptr, "textures/floor.xpm");
	if (!textures->floor)
		return (perror("textures/floor.xpm"), NULL);
	textures->frame = img(mlxptr, "textures/frames.xpm");
	if (!textures->frame)
		return (perror("textures/frames.xpm"), NULL);
	textures->frame2 = img(mlxptr, "textures/frames2.xpm");
	if (!textures->frame2)
		return (perror("text/ures/frames2.xpm"), NULL);
	textures->coll = img(mlxptr, "textures/colls.xpm");
	if (!textures->coll)
		return (perror("textures/colls.xpm"), NULL);
	textures->out_exit = img(mlxptr, "textures/exit.xpm");
	if (!textures->out_exit)
		return (perror("textures/exit.xpm"), NULL);
	textures->inter_wall = img(mlxptr, "textures/inter_walls.xpm");
	if (!textures->inter_wall)
		return (perror("textures/inter_walls.xpm"), NULL);
	return ("success");
}

void	lunch_game(t_game game)
{
	mlx_loop_hook(game.data.mlxptr, &rendering, &game);
	mlx_hook(game.data.winptr, 2, 0, movement, &game);
	mlx_hook(game.data.winptr, 17, 0, close_win, &game);
	mlx_loop(game.data.mlxptr);
}
int	main(int ac, char **av)
{	
	t_game	game;

	atexit(f);

	error_check(av, ac, &game);
	game.map[game.player.y][game.player.x] = '0';
	game.data.mlxptr = mlx_init();
	if (!game.data.mlxptr)
		return (perror ("mlx_init\n"), 1);
	if (!textures(&game.textures, game.data.mlxptr))
		return 1;
	game.map[game.player.y][game.player.x] = '0';
	game.data.winptr = mlx_new_window(game.data.mlxptr,80 * game.map_size.x, game.map_size.y * 80, "youssra_so_long");
	if (!game.data.winptr)
		return 1;
	lunch_game(game);
	return (0);
}

// int main()
// {
// 	int fd = open("youssra", O_CREAT | O_RDWR, 0644);

// 	char *line= get_next_line(fd);

// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line= get_next_line(fd);
// 	}
// }
