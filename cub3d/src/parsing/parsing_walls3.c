/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_walls3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:25:35 by negambar          #+#    #+#             */
/*   Updated: 2025/03/19 12:14:11 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	is_first(t_map *map, int i)
{
	int	j;
	int	skip;

	j = i + 1;
	skip = skip_spaces(map->map[j]);
	if (map->map[j])
		if (map->map[j][skip] && map->map[j][skip] != '\n')
			return (1);
	return (0);
}

static int	first_wall(char **map, int i, int end, int start)
{
	int	start_after;
	int	end_after;

	start_after = skip_spaces(map[i + 1]);
	end_after = trim_spaces(map[i + 1]);
	while (start_after < start)
	{
		if (map[i + 1][start_after] != '1')
			return (1);
		start_after++;
	}
	while (end_after > end)
	{
		if (map[i + 1][end_after] != '1')
			return (1);
		end_after--;
	}
	return (0);
}

int	last_wall(char **map, int i, int end, int start)
{
	int	start_before;
	int	end_before;

	start_before = skip_spaces(map[i - 1]);
	end_before = trim_spaces(map[i - 1]);
	while (start_before < start)
	{
		if (map[i - 1][start_before] != '1')
			return (1);
		start_before++;
	}
	while (end_before > end)
	{
		if (map[i - 1][end_before] != '1')
			return (1);
		end_before--;
	}
	return (0);
}

int	wall_space(t_map *s_map, char **map, int i, int space)
{
	int	space_check;
	int	last_char;

	space_check = 0;
	last_char = trim_spaces(map[i]);
	while (1)
	{
		space = space_checker(map[i], space, &space_check);
		if (space_check == space || space == last_char)
			return (0);
		if (is_first(s_map, i))
		{
			if (first_other_walls(s_map, map, i, space))
				return (1);
		}
		else
		{
			if (last_other_walls(map, i, space))
				return (1);
		}
	}
	return (0);
}

int	check_firsandlast(t_map *s_map, int i, int end, int start)
{
	int		ret;
	int		space;
	char	**map;

	map = s_map->map;
	space = 0;
	ret = 0;
	if (is_first(s_map, i))
	{
		if (first_wall(map, i, end, start))
			ret++;
	}
	else
	{
		if (last_wall(map, i, end, start))
			ret++;
	}
	if (ret)
		return (1);
	if (wall_space(s_map, map, i, space))
		ret++;
	return (ret);
}
