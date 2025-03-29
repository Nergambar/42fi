/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:23:02 by negambar          #+#    #+#             */
/*   Updated: 2025/03/27 11:30:03 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	check_char_helper(t_map *map, int j, int i)
{
	if (map->map[i][j] == ' ')
	{
		if (((size_t)j >= ft_strlen(map->map[i + 1])
				|| ft_strchr("1 \n", map->map[i + 1][j]))
				&& ((size_t)j >= ft_strlen(map->map[i - 1])
				|| ft_strchr("1 \n", map->map[i - 1][j]))
				&& (!map->map[i][j + 1]
				|| ft_strchr("1 \n", map->map[i][j + 1]))
				&& (!map->map[i][j - 1]
				|| ft_strchr("1 \n", map->map[i][j - 1])))
		{
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int	check_segment(int *end, int *end_before, int i, char **map)
{
	while (*end < *end_before)
	{
		if (map[i - 1][*end_before] != '1')
		{
			if (map[i - 1][*end_before] == ' ')
			{
				while (*end_before > 0 && map[i - 1][*end_before] == ' ')
					(*end_before)--;
				return (check_surrounded_end(map, i, *end, *end_before));
			}
			else
				return (1);
		}
		(*end_before)--;
	}
	return (0);
}
