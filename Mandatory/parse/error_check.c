/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 04:17:26 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/14 06:50:01 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	error_check(char **av, int ac)
{
	char	*file;
	char	**map;
	char	**tmp;

	if (!av || !*av)
		return ;
	check_extension(av, ac);
	file = filename(av);
	map = get_map(file);
	walls_check(map);
	data_check(map);
	check_chars(map);
	tmp = map;
	check_path(tmp);
}
