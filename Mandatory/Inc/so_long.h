/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:41:37 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/27 11:14:14 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../../lib/Libft/libft.h"
#include <mlx.h>


#define Exit_1 
#define Exit_1 
#define Exit_1 
#define Exit_1 

typedef struct s_coords
{
	int x;
	int y;
} t_coords;

typedef	struct s_sprites
{
	void	*img;
	void	*next;
}	t_sprite;


typedef struct s_textures
{
	void *floor;

	void *frame;
	void *frame2;
	void *inter_wall;

	void *coll;
	void *out_exit;
	void *player;
	void	*cage;
	// t_sprite *player;
	// t_sprite	*exit;

} t_textures;

typedef struct s_data
{
	void *mlxptr;
	void *winptr;

} t_data;

typedef struct s_game
{
	t_data	data;

	char **map;
	t_coords map_size;
	t_coords player;
	int colls;
	int	moves;

	t_textures textures;

} t_game;

void 	path(char **map, t_coords size, int x, int y);
void 	check_path(t_game *game, char **tmp);
void 	error_check(char **av, int ac, t_game *game);
void	move(t_game *game, int x, int y);
void 	free_array(char **str);
void	 *ft_free(char **split, int i);

int   	 rendering(t_game *game);

int check_extension(char **av, int ac);
int rectangular_check(char **map);
int walls_check(char **map);

// player coords && colls calcul
int data_check(t_game *game);
int check_chars(char **map);

char *filename(char **av);
char **get_map(char *file);

#endif