/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:07:21 by negambar          #+#    #+#             */
/*   Updated: 2025/03/08 13:54:53 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

/**
 * unit_circle - Checks if angle is in specific range for axis.
 * @angle: Angle in radians.
 * @c: Axis ('x' or 'y').
 *
 * Return: 1 if in range, else 0.
 */
int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (PI / 2) && angle < (3 * PI) / 2)
			return (1);
	}
	return (0);
}
/**
 * inter_check - Adjusts intersection and step based on angle and horizon.
 * Return: -1 if intersection adjusted, 1 otherwise.
 */

int	inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * PI);
	if (angle > (2 * PI))
		angle -= (2 * PI);
	return (angle);
}

bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}
