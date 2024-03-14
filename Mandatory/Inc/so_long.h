/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:41:37 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/14 06:41:00 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../lib/Libft/libft.h"

typedef struct s_coords
{
	int	x;
	int	y;
}			t_coords;

typedef struct s_game
{
	char		**map;
	t_coords	*map_size;
	t_coords	*player;

}		t_game;

void		path(char **map, t_coords *size, int x, int y);
void		error_check(char **av, int ac);
void		free_array(char **str);
void		check_path(char **map);

int			check_extension(char **av, int ac);
int			rectangular_check(char **map);
int			walls_check(char **map);
int			data_check(char **map);
int			check_chars(char **map);

t_coords	*mapsize(char **map);
t_coords	*x_y(char **map);

char		*filename(char **av);
char		**get_map(char *file);

#endif