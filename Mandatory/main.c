/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:46:30 by ychagri           #+#    #+#             */
/*   Updated: 2024/04/27 20:08:49 by ychagri          ###   ########.fr       */
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

int	movement(int key, t_game *game)
{
	//printf("key: %d\n", key);
	//if (key == )
	//	exit(0); // fucntion exits with a message and frees all of the game struct
	//else if (key == 2)
	
	//else if (key == 3)
	
	//else if (key == 4)
	
	//else if (key == 5)
	
	//else if (key == 6)
		
	return (0);
}

typedef struct s_so_long{
	
	void	*mlx;
	void	*win;
	int		k;
	int		x;
	int		y;
	void *floor;
	void *wall;
	void *coll;
	void *out_exit;
	void *player;
}t_so_long;
void	lunch_game(t_game game)
{
	t_so_long *vars;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx,game.map_size.x * 80, game.map_size.y * 80, "so_long");
	//player = mlx_xpm_file_to_image(mlx, "textures/player.xpm", &k, &k);
	//floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &k, &k);
	//wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &k, &k);
	//coll = mlx_xpm_file_to_image(mlx, "textures/coll.xpm", &k, &k);
	//out_exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &k, &k);
	//game.map[game.player.y][game.player.x] = '0';
	//y = 0;
	//while (y < game.map_size.y)
	//{
	//	//ft_printf("%s\n", game.map[y]);
	//	x = 0;
	//	write(1,"\n",1);
	//	while(x < game.map_size.x)
	//	{
	//		if (game.map[y][x] == '0')
	//			write(1,"0",1);
	//			//mlx_put_image_to_window(mlx, win, floor, x * 80, y * 80);
	//		//else if (game.map[y][x] == 'P')
	//		//	write(1,"P",1);
	//			//mlx_put_image_to_window(mlx, win, player, x * 80, y * 80);
	//		else if (game.map[y][x] == 'E')
	//			write(1,"E",1);
	//			//mlx_put_image_to_window(mlx, win, out_exit, x * 80, y * 80);
	//		else if (game.map[y][x] == 'C')
	//			write(1,"C",1);
	//			//mlx_put_image_to_window(mlx, win, coll, x * 80, y * 80);
	//		else if (game.map[y][x] == '1')
	//			write(1,"1",1);
	//			//mlx_put_image_to_window(mlx, win, wall, x * 80, y * 80);
	//			x++;
	//	}
	//	y++;
	//}
	//mlx_loop();	// drawing 
	// mlx loop hook // catch hooks 
	mlx_hook(win, 2, 0, movement, &game);
	mlx_loop(mlx);
}
int	main(int ac, char **av)
{
	t_game	game;
	
	//atexit(f);
	if (ac == 1)
		exit(0);
	error_check(av, ac, &game);
	lunch_game(game);
	return (0);
}
