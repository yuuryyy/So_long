/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssra <youssra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 04:17:26 by ychagri           #+#    #+#             */
/*   Updated: 2024/06/22 15:00:46 by youssra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_free(char **split, int i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
}

void	check_rec(t_game *game)
{
	size_t	len;
	int		i;

	len = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len)
			return (ft_putstr_fd("\033[31mError\n\tnon rectangular map!\n", 2),
				free_array(game->map), exit(1));
		i++;
	}
	game->map_size.x = len;
	game->map_size.y = i;
}

char	**tmp_map(t_game *game)
{
	int		y;
	char	**tmp;

	y = 0;
	tmp = malloc ((game->map_size.y + 1) * sizeof(char *));
	if (!tmp)
		return (ft_putstr_fd("\033[31mError\n\tmalloc failed!", 2),
			exit(1), NULL);
	while (game->map[y])
	{
		tmp[y] = malloc(game->map_size.x + 1);
		if (!tmp[y])
			return (ft_putstr_fd("\033[31mError\n\t malloc failed!", 2),
				ft_free(tmp, y),
				free_array(game->map), exit(1), NULL);
		tmp[y] = ft_strcpy(tmp[y], game->map[y]);
		y++;
	}
	tmp[y] = 0;
	return (tmp);
}

void	error_check(char **av, int ac, t_game *game)
{
	char	*file;
	char	**tmp;

	if (!av || !*av)
		return ;
	check_extension(av, ac);
	file = filename(av);
	game->map = get_map(file);
	walls_check(game->map);
	check_chars(game->map);
	data_check(game);
	tmp = tmp_map(game);
	check_path(game, tmp);
}
