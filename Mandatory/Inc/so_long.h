/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:41:37 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/28 05:37:22 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../lib/Libft/libft.h"
# include <mlx.h>

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef enum t_moves
{
	UP = 126,
	W = 13,
	LEFT = 123,
	A = 0,
	DOWN = 125,
	S = 1,
	RIGHT = 124,
	D = 2,
	ESC = 53
}	t_moves;

typedef struct s_sprites
{
	void	*img;
	void	*next;
}	t_sprite;

typedef struct s_textures
{
	void	*floor;

	void	*frame;
	void	*frame2;
	void	*inter_wall;

	void	*coll;
	void	*out_exit;
	void	*player;
	void	*cage;
}	t_textures;

typedef struct s_data
{
	void	*mlxptr;
	void	*winptr;

}	t_data;

typedef struct s_game
{
	t_textures	textures;
	t_coords	map_size;
	t_coords	player;
	t_data		data;
	char		**map;
	int			colls;
	int			moves;
}	t_game;

void	path(char **map, t_coords size, int x, int y);
void	error_check(char **av, int ac, t_game *game);
void	check_path(t_game *game, char **tmp);
void	move(t_game *game, int x, int y);
void	*ft_free(char **split, int i);
void	free_array(char **str);

int		check_extension(char **av, int ac);
int		rendering(t_game *game);
int		rectangular_check(char **map);
int		walls_check(char **map);
// player coords && colls calcul
int		data_check(t_game *game);
int		check_chars(char **map);

char	*filename(char **av);
char	**get_map(char *file);

#endif