/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:41:37 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/13 06:11:54 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../lib/Libft/libft.h"

typedef struct s_coords
{
	int	x;
	int	y;
}			p_coords;


typedef struct s_game
{
	char	**map;
	p_coords	*map_size;
	p_coords	*player;
	
}		game;


int		check_extension(char **av, int ac);
char	*filename(char **av);
p_coords	*x_y(char **map);
char	**get_map(char *file);
int	walls_check(char **map);
int	rectangular_check(char **map);
int	data_check(char **map);
int	check_chars(char **map);
p_coords	*mapsize(char **map);
void	path(char **map, p_coords *size,int x, int y);

#endif