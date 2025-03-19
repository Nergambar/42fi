/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:15:31 by negambar          #+#    #+#             */
/*   Updated: 2025/03/19 11:05:30 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	map_parsing(char **av, t_map *map)
{
	char	**tmp_map;

	tmp_map = check_and_read(av);
	if (!tmp_map)
		return (1);
	if (get_map(tmp_map, map) || get_textures(tmp_map, map))
	{
		free_map(map);
		free_matrix(tmp_map);
		return (1);
	}
	free_matrix(tmp_map);
	if (check_characters(map))
	{
		free_map(map);
		return (1);
	}
	if (check_configuration(map) || check_map_h_w(map))
	{
		free_map(map);
		return (1);
	}
	return (0);
}

char	**check_and_read(char **av)
{
	char	*tmp;
	char	*path;
	char	**tmp_map;

	tmp = ft_strnstr(av[1], ".cub", ft_strlen(av[1]));
	if (!tmp || ft_strcmp(tmp, ".cub") != 0)
		return (NULL);
	path = ft_strjoin("./", av[1]);
	tmp_map = NULL;
	tmp_map = read_map(path);
	free(path);
	if (!tmp_map)
		return (NULL);
	return (tmp_map);
}

int	checkmap(t_map *map)
{
	int	i;
	int	j;

	i = map->map_lines - 1;
	while (i > 3)
	{
		j = skip_spaces(map->map[i]);
		if (map->map[i][j] == '1')
			return (0);
		else if (map->map[i][j] != '\n' && map->map[i][j] != 0
				&& map->map[i][j] != '\t' && map->map[i][j] != ' ')
			return (1);
		i--;
	}
	return (0);
}

int	get_map(char **tmp_map, t_map *map)
{
	int	i;
	int	j;
	int	size;
	int	check_line;

	j = 0;
	i = 0;
	while (tmp_map[i] && in_map(tmp_map[i], 0))
		i++;
	check_line = i;
	while (tmp_map[check_line])
		check_line++;
	size = check_line - i;
	map->map = ft_calloc(size + 1, sizeof(char *));
	if (!map->map)
		return (1);
	while (tmp_map[i] && j != size)
	{
		map->map[j] = ft_strdup(tmp_map[i]);
		j++;
		i++;
	}
	map->map[j] = NULL;
	map->map_lines = size;
	return (checkmap(map));
}

int	get_textures(char **tmp, t_map *map)
{
	int	check;
	int	i;
	int	j;

	check = check_textures(tmp);
	if (!check)
		return (1);
	j = 0;
	i = -1;
	map->texture = calloc(check + 1, sizeof(char *));
	if (!map->texture)
		return (1);
	while (tmp[++i] && check != j)
	{
		if (!in_texture(tmp[i]))
			map->texture[j++] = cub3d_strdup(tmp[i]);
	}
	map->texture[j] = NULL;
	return (0);
}
