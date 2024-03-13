/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:46:30 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/13 06:45:57 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inc/so_long.h"

//void	f(){system("leaks so_long");}

int	main(int ac, char **av)
{
	char	*file;

	//atexit(f);
	if (ac == 1)
		exit(0);
	if (!check_extension(av, ac))
		return (ft_putstr_fd("Error\n Invalid filename!!\n", 2), 1);
	file = filename(av);
	char **map = get_map(file);
	if (!map)
		return (ft_putstr_fd("Error\n File can't be opened!!\n", 2), 1);
	if (!rectangular_check(map))
				return (ft_putstr_fd("Error\n Non rectangular map!!\n", 2), 1);
	if (!walls_check(map))
		return (ft_putstr_fd("Error\n Missing walls !!\n", 2), 1);
	if (!data_check(map))
		return (ft_putstr_fd("Error\n Invalid number of a component!!\n", 2), 1);
	if (!check_chars(map))
		return (ft_putstr_fd("Error\n Invalid Symbols!!\n", 2), 1);
	char **tmp = map;
	p_coords *size = mapsize(map);
	printf("x = %d \\ y = %d\n",size->x,size->y);
	p_coords *player = x_y(map);
	printf("x = %d \\ y = %d\n", player->x, player->y);
	path(tmp, size, player->x, player->y);
	//int i = 0;
	//while(tmp[i])
	//{
	//	printf("%s\n", tmp[i]);
	//	i++;
	//}
	//player = mapsize(map);
	//char *line;
	//while (1)
	//{
	//	line = get_next_line(fd);
	//	if (!line)
	//		break ;
	//	map = ft_strjoin2(map, line);
	//	free(line);
	//}
	//int i = 0;
	//while (map[i])
	//{
	//	printf("%s\n", map[i++]);
	//}
	//printf("%d\n", walls_check(map));
	
}