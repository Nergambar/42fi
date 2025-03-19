/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:48:30 by negambar          #+#    #+#             */
/*   Updated: 2025/03/17 14:54:35 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	check_and_skip_range(char *str, char *tmp, t_map *map, char type)
{
	int		num;
	int		space;
	char	c;

	c = str[0];
	space = 0;
	if (c != ',')
	{
		if (c != '\0')
			return (0);
	}
	num = ft_atoi(tmp);
	if (num >= 0 && num <= 255)
	{
		alloc_colors(type, num, map);
		if (c != '\0')
		{
			space++;
			space += skip_spaces(&str[space]);
			return (space);
		}
		else
			return (-1);
	}
	return (0);
}

char	**check_alloc_path(char *path)
{
	int		fd;
	int		count;
	char	**temp_map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	count = count_line(fd);
	close(fd);
	temp_map = ft_calloc(count + 1, sizeof(char *));
	if (!temp_map)
		return (NULL);
	return (temp_map);
}

void	alloc_colors(char type, int num, t_map *map)
{
	if (type == 'F')
	{
		if (map->f_alloc == 0)
			map->f_color = malloc(3 * sizeof(int *));
		map->f_color[map->f_alloc] = malloc(1 * sizeof(int));
		map->f_color[map->f_alloc][0] = num;
		map->f_alloc++;
	}
	else
	{
		if (map->c_alloc == 0)
			map->c_color = malloc(3 * sizeof(int *));
		map->c_color[map->c_alloc] = malloc(1 * sizeof(int));
		map->c_color[map->c_alloc][0] = num;
		map->c_alloc++;
	}
}

int	check_len_color(char *str)
{
	int	check;
	int	i;
	int	comma;

	comma = 0;
	i = 0;
	check = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ' && (str[i] != ','))
		{
			while (str[i] && str[i] != ' ' && (str[i] != ','))
			{
				if (str[i] < '0' || str[i] > '9')
					return (1);
				i++;
			}
			check++;
		}
		if (str[i] && (str[i] != ',' || ++comma))
			i++;
	}
	if (check == 3 && comma == 2)
		return (0);
	return (1);
}

char	*tmp_num(char *tmp, char *texture)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (texture[i] && (texture[i] >= '0' && texture[i] <= '9'))
	{
		if (j > 3)
			return (NULL);
		tmp[j++] = texture[i];
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}
