/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:40:26 by negambar          #+#    #+#             */
/*   Updated: 2025/02/26 15:21:29 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static	int	check_direction_down2(t_game *game, int code, int tmp_x, int tmp_y)
{
	float	tmp_wall;

	if (code == 2)
	{
		if (game->map[tmp_y][tmp_x + 1]
			&& game->map[(int)tmp_y][(int)tmp_x + 1] == '1')
		{
			tmp_wall = (float)((tmp_x + 1) * TILE_SIZE);
			if (game->player.p_x >= (tmp_wall - 12))
				return (1);
		}
	}
	else if (code == 3)
	{
		if (game->map[tmp_y + 1][tmp_x]
			&& game->map[(int)tmp_y + 1][(int)tmp_x] == '1')
		{
			tmp_wall = (float)((tmp_y + 1) * TILE_SIZE);
			if (game->player.p_y >= (tmp_wall - 10))
				return (1);
		}
	}
	return (0);
}

int	check_direction_down(t_game *game, int code)
{
	int		tmp_x;
	int		tmp_y;
	float	tmp_wall;

	tmp_x = (int)(game->player.p_x) / TILE_SIZE;
	tmp_y = (int)(game->player.p_y) / TILE_SIZE;
	if (code == 0)
	{
		if (game->map[tmp_y - 1][tmp_x]
			&& game->map[(int)tmp_y - 1][(int)tmp_x] == '1')
		{
			tmp_wall = (float)((tmp_y) * TILE_SIZE);
			if (game->player.p_y <= (tmp_wall + 5))
				return (1);
		}
	}
	else if (code == 1)
	{
		if (mini_helper2(game, tmp_x, tmp_y))
			return (1);
	}
	return (check_direction_down2(game, code, tmp_x, tmp_y));
}

static int	check_direction_up2(t_game *game, int code, int tmp_x, int tmp_y)
{
	float	tmp_wall;

	if (code == 2)
	{
		if (game->map[tmp_y][tmp_x + 1]
			&& game->map[(int)tmp_y][(int)tmp_x + 1] == '1')
		{
			tmp_wall = (float)((tmp_x + 1) * TILE_SIZE);
			if (game->player.p_x >= (tmp_wall - 13))
				return (1);
		}
	}
	else if (code == 3)
	{
		if (game->map[tmp_y + 1][tmp_x]
			&& game->map[(int)tmp_y + 1][(int)tmp_x] == '1')
		{
			tmp_wall = (float)((tmp_y + 1) * TILE_SIZE);
			if (game->player.p_y >= (tmp_wall - 11))
				return (1);
		}
	}
	return (0);
}

static	int	mini_helper(t_game *game, int tmp_x, int tmp_y)
{
	float	tmp_wall;

	tmp_wall = 0;
	if (game->map[tmp_y][tmp_x - 1]
			&& game->map[(int)tmp_y][(int)tmp_x - 1] == '1')
	{
		tmp_wall = (float)((tmp_x) * TILE_SIZE);
		if (game->player.p_x <= (tmp_wall + 5))
			return (1);
	}
	return (0);
}

int	check_direction_up(t_game *game, int code)
{
	int		tmp_x;
	int		tmp_y;
	float	tmp_wall;

	tmp_x = (int)(game->player.p_x) / TILE_SIZE;
	tmp_y = (int)(game->player.p_y) / TILE_SIZE;
	if (code == 0)
	{
		if (game->map[tmp_y - 1][tmp_x]
			&& game->map[(int)tmp_y - 1][(int)tmp_x] == '1')
		{
			tmp_wall = (float)((tmp_y) * TILE_SIZE);
			if (game->player.p_y <= (tmp_wall + 10))
				return (1);
		}
	}
	else if (code == 1)
	{
		if (mini_helper(game, tmp_x, tmp_y))
			return (1);
	}
	return (check_direction_up2(game, code, tmp_x, tmp_y));
}
