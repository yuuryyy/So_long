/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:18:10 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/13 01:38:58 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

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
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = ft_strjoin2(map, line);
		free(line);
	}
	map2d = ft_split(map, '\n');
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
			return (0);
		i++;
	}
	return (1);
}

int	walls_check(char **map)
{
	char	**tmp;
	int		k;
	int		len;

	if (!map || !*map)
		return (0);
	k = 0;
	len = 0;
	tmp = map;
	while (tmp[len])
		len++;
	len--;
	while (tmp[0][k] && tmp[len][k])
	{
		if (tmp[0][k] != '1' || tmp[len][k] != '1')
			return (0);
		k++;
	}
	len = ft_strlen(map[0]) - 1;
	k = 0;
	while (tmp[k])
	{
		if (tmp[k][0] != '1' || tmp[k][len] != '1')
			return (0);
		k++;
	}
	return (1);
}
