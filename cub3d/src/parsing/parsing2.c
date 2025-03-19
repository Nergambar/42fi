/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:41:38 by negambar          #+#    #+#             */
/*   Updated: 2025/03/19 15:20:05 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

char	**read_map(char *path)
{
	int		fd;
	char	**temp_map;
	char	*temp_line;
	int		i;

	i = 0;
	temp_map = check_alloc_path(path);
	if (!temp_map)
		return (NULL);
	fd = open(path, O_RDONLY);
	while (1)
	{
		temp_line = get_next_line(fd);
		if (!temp_line)
		{
			free(temp_line);
			break ;
		}
		temp_map[i++] = ft_strdup(temp_line);
		free(temp_line);
	}
	temp_map[i] = NULL;
	close(fd);
	return (temp_map);
}

int	check_line_config(t_map *map, char *str)
{
	int		i;
	int		j;
	int		check;

	check = 0;
	i = 0;
	while (map->texture[i])
	{
		j = ft_strlen(str);
		if (j == 2 && !ft_strncmp(map->texture[i], str, j))
		{
			if (!check_texture_acces(map->texture[i], j))
				check++;
		}
		else if (j == 1 && !ft_strncmp(map->texture[i], str, j))
		{
			if (!check_colors(map->texture[i], str, j, map))
				check++;
		}
		i++;
	}
	if (check == 1)
		return (0);
	return (1);
}

int	check_colors(char *texture, char *str, int i, t_map *map)
{
	char	*tmp;

	i += skip_spaces(texture + i);
	if (check_len_color(&texture[i]))
		return (1);
	tmp = calloc(4, sizeof(char));
	if (!tmp)
		return (1);
	if (loop_colors(map, tmp, &texture[i], str))
		return (1);
	return (0);
}

int	check_char(t_map *map, int start, int end, int i)
{
	int	j;

	j = start -1;
	while (map->map[i][++j] && j != end)
	{
		if (ft_strchr("0NSEW", map->map[i][j]))
		{
			if (!(ft_strchr("NSEW10", map->map[i + 1][j])
				&& ft_strchr("NSEW10", map->map[i][j + 1])
				&& ft_strchr("NSEW10", map->map[i - 1][j])
				&& ft_strchr("NSEW10", map->map[i][j - 1])))
				return (1);
		}
		if (!ft_strchr("10NSEW ", map->map[i][j]) && map->map[i][j] != '\n')
			return (1);
		if (ft_strchr("NSEW", map->map[i][j]))
		{
			if (map->dir)
				return (1);
			pos_or_dir(map->map[i][j], i, j, map);
		}
	}
	return (0);
}

void	pos_or_dir(char c, int i, int j, t_map *map)
{
	map->dir = c;
	map->p_init_pos[0] = i;
	map->p_init_pos[1] = j;
}
