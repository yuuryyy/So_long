/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:46:30 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/26 08:21:36 by ychagri          ###   ########.fr       */
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

//typedef enum {
	//W = 12,
	
//}

// int	movement(int key, t_game *game)
// {
	//printf("key: %d\n", key);
	//if (key == )
	//	exit(0); // fucntion exits with a message and frees all of the game struct
	//else if (key == 2)
	
	//else if (key == 3)
	
	//else if (key == 4)
	
	//else if (key == 5)
	
	//else if (key == 6)
		
// 	return (0);
// }

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
	int		y;
	int		x;

	game.data.mlxptr = mlx_init();
	if (!game.data.mlxptr)
		return (perror ("mlx_init\n"), exit (1));
	if (!textures(&game.textures, game.data.mlxptr))
		exit (1);
	game.data.winptr = mlx_new_window(game.data.mlxptr,80 * game.map_size.x, game.map_size.y * 80, "youssra_so_long");
	if (!game.data.winptr)
		exit(1);
	// game.map[game.player.y][game.player.x] = '0';
	y = 0;
	while (y < game.map_size.y)
	{
fprintf(stderr, "sudhiosdhsdis");
		x = 0;
		while(x < game.map_size.x)
		{
			mlx_put_image_to_window(game.data.mlxptr,game.data.winptr,game.textures.floor, x * 80, y * 80);
			if (game.map[y][x] == 'P')
				mlx_put_image_to_window(game.data.mlxptr,game.data.winptr,game.textures.player, x * 80, y * 80);
			else if (game.map[y][x] == 'E')
				mlx_put_image_to_window(game.data.mlxptr,game.data.winptr,game.textures.out_exit, x * 80, y * 80);
			else if (game.map[y][x] == 'C')
				mlx_put_image_to_window(game.data.mlxptr,game.data.winptr,game.textures.coll, x * 80, y * 80);
			else if (game.map[y][x] == '1')
			{
				if (y == 0 || x == 0 || x == game.map_size.x - 1 || y == game.map_size.y - 1)
				{
					if (x % 2 == 0)
						mlx_put_image_to_window(game.data.mlxptr, game.data.winptr, game.textures.frame, x * 80, y * 80);
					else
						mlx_put_image_to_window(game.data.mlxptr, game.data.winptr, game.textures.frame2, x * 80, y * 80);
				}
				else
					mlx_put_image_to_window(game.data.mlxptr, game.data.winptr, game.textures.frame, x * 80, y * 80);
			}
				x++;
		}
		y++;
	}
	mlx_loop(game.data.mlxptr);	// drawing 
	// mlx_hook(win, 2, 0, movement, &game);
	// mlx_loop(mlx);
}
int	main(int ac, char **av)
{	
	t_game	game;

	// atexit(f);

	error_check(av, ac, &game);
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
