/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:06:42 by negambar          #+#    #+#             */
/*   Updated: 2024/04/15 12:56:18 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count(char **mtx, char c, int i, int j)
{
	int	ccount;

	ccount = 0;
	while (mtx[i])
	{
		j = 0;
		while (mtx[i][j] && mtx[i][j] != '\n')
		{
			if (mtx[i][j] == c)
				ccount++;
			j++;
		}
		i++;
	}
	return (ccount);
}

int	check_quantity(char **mtx, t_struct *sprites)
{
	int	exit_count;
	int	player_count;
	int	coll_count;

	exit_count = count(mtx, 'E', 0, 0);
	player_count = count(mtx, 'P', 0, 0);
	coll_count = count(mtx, 'C', 0, 0);
	if (player_count != 1 || coll_count == 0 || exit_count != 1
		|| !error_check(mtx) || !wall_maria(mtx))
		return (0);
	sprites->ecount = exit_count;
	sprites->collcount = coll_count;
	sprites->ecount = player_count;
	return (1);
}

void	floodfill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'X';
		return ;
	}
	map[y][x] = 'X';
	floodfill(map, y + 1, x);
	floodfill(map, y - 1, x);
	floodfill(map, y, x + 1);
	floodfill(map, y, x - 1);
}

int	checkfill(char **mtx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mtx[i])
	{
		while (mtx[i][j])
		{
			if (mtx[i][j] == 'C' || mtx[i][j] == 'E' || mtx[i][j] == 'P')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	checkmap(t_struct *sprites, char **mtx, int i, int j)
{
	check_for_player(sprites);
	i = sprites->pos[0];
	j = sprites->pos[1];
	if (!check_quantity(mtx, sprites))
		return (0);
	floodfill(mtx, j, i);
	if (!checkfill(mtx))
		return (0);
	return (1);
}
