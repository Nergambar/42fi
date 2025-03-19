/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:33:54 by negambar          #+#    #+#             */
/*   Updated: 2025/03/19 15:18:28 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static int	is_last(t_map *map, int i)
{
	size_t	j;

	i++;
	if (!map->map[i])
		return (0);
	j = 0;
	while (map->map[i][j] == ' ' || map->map[i][j] == '\t')
		j++;
	if (j != (ft_strlen(map->map[i]) - 1))
		return (1);
	return (0);
}

int	check_characters(t_map *map)
{
	int	i;
	int	start;
	int	end;
	int	tmp;

	i = -1;
	tmp = 0;
	while (map->map[++i])
	{
		start = skip_spaces(map->map[i]);
		end = trim_spaces(map->map[i]);
		if (check_char(map, start, end, i))
			return (1);
		if (end <= 0 && ++tmp)
			continue ;
		if ((i - tmp == 0 || !is_last(map, i))
			&& check_firsandlast(map, i, end, start))
			return (1);
		if (!(i - tmp == 0 || i == map->map_lines - 1)
			&& check_surrounded_wall(map->map, i, start, end))
			return (1);
	}
	if (map->p_init_pos[0] == -1)
		return (1);
	return (0);
}
