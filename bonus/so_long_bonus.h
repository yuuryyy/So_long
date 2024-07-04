/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:10:27 by ychagri           #+#    #+#             */
/*   Updated: 2024/07/04 12:40:36 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/Libft/libft.h"
# include <mlx.h>
# include <stdbool.h>
# include <time.h>

# define MOVES "textures/moves.xpm" 

# define P1 "textures/1.xpm" 
# define P2 "textures/2.xpm" 
# define P3 "textures/3.xpm" 
# define P4 "textures/4.xpm" 
# define P5 "textures/5.xpm" 
# define P6 "textures/6.xpm" 
# define P7 "textures/7.xpm" 
# define P8 "textures/8.xpm" 
# define P9 "textures/9.xpm" 
# define P10 "textures/10.xpm" 
# define P11 "textures/11.xpm" 
# define P12 "textures/12.xpm"

# define C1 "textures/coll1.xpm" 
# define C2 "textures/coll2.xpm"

# define E1 "textures/e1.xpm"
# define E2 "textures/e2.xpm"
# define E3 "textures/e3.xpm"
# define E4 "textures/e4.xpm"

# define EN1 "textures/en1.xpm" 
# define EN2 "textures/en2.xpm" 
# define EN3 "textures/en3.xpm" 
# define EN4 "textures/en4.xpm" 
# define EN5 "textures/en5.xpm" 
# define EN6 "textures/en6.xpm" 
# define EN7 "textures/en7.xpm" 
# define EN8 "textures/floor_b.xpm" 
# define EN9 "textures/floor_b.xpm" 
# define EN10 "textures/floor_b.xpm" 


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

typedef struct s_data
{
	void	*mlxptr;
	void	*winptr;

}	t_data;

typedef struct s_textures
{
	void	*floor;

	void	*frame;
	void	*frame2;

	t_list	*coll;
	t_list	*out_exit;
	t_list	*player;
	t_list	*enemy;
	void	*cage;
	unsigned int	frames;
}	t_textures;

typedef struct s_game
{
	t_textures	textures;
	t_coords	map_size;
	t_coords	player;
	t_data		data;
	char		**map;
	int			colls;
	bool		patrol;
	int			moves;
}	t_game;

void	init_textures(t_textures *textures, void *mlxptr, t_game *game);
void	path(char **map, t_coords size, int x, int y);
void	error_check(char **av, int ac, t_game *game);
void	check_path(t_game *game, char **tmp);
void	move(t_game *game, int x, int y);
void	*ft_free(char **split, int i);
void	free_array(char **str);

int		check_extension(char **av, int ac);
int		rectangular_check(char **map);
int		rendering(t_game *game);
int		data_check(t_game *game);
int		check_chars(char **map);
int		walls_check(char **map);
char	*filename(char **av);
char	**get_map(char *file);

#endif