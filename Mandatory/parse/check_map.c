/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:18:10 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/28 05:39:19 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

int	check_newlines(char *map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
	{
		if ((map[i + 1] && map[i] == '\n' && map[i + 1] == '\n')
			|| (map[i] == '\n' && map[i + 1] == '\0'))
			return (ft_putstr_fd("\033[31mError\n\textra new lines !!\n", 2),
				free(map), exit(1), 0);
		i++;
	}
	return (1);
}

char	**get_map(char *file)
{
	int		fd;
	char	*map;
	char	*line;
	char	**map2d;

	map = NULL;
	if (!file)
		return (NULL);
	fd = open(file, O_RDONLY);
	free(file);
	if (fd == -1)
		return (ft_putstr_fd("\033[31mError\n\tOpening file !!\n", 2),
			exit (1), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = ft_strjoin2(map, line);
		free(line);
	}
	check_newlines(map);
	map2d = ft_split(map, '\n');
	free (map);
	return (map2d);
}

int	rectangular_check(char **map)
{
	int		i;
	char	**tmp;

	if (!map || !*map)
		return (0);
	i = 0;
	tmp = map;
	while (tmp[i + 1])
	{
		if (ft_strlen(tmp[i]) != ft_strlen(tmp[i + 1]))
		{
			ft_putstr_fd("\033[31mError\n\tNon rectangular map!!\n", 2);
			exit (1);
		}
		i++;
	}
	return (1);
}

void	err_walls(char **map)
{
	ft_putstr_fd("\033[31mError\n\tMissing walls !!\n", 2);
	free_array(map);
	exit (1);
}

int	walls_check(char **map)
{
	int		k;
	int		len;

	if (!map || !*map)
		return (0);
	k = 0;
	len = 0;
	while (map[len])
		len++;
	while (map[0][k] && map[len - 1][k])
	{
		if (map[0][k] != '1' || map[len - 1][k] != '1')
			err_walls(map);
		k++;
	}
	len = ft_strlen(map[0]) - 1;
	k = 0;
	while (map[k])
	{
		if (map[k][0] != '1' || map[k][len] != '1')
			err_walls(map);
		k++;
	}
	return (1);
}
