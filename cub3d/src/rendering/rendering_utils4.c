/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:08:26 by negambar          #+#    #+#             */
/*   Updated: 2025/03/28 14:13:47 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

/*
 * gets the color of a specific pixel in a texture
 */
int	get_texture_color(t_img *texture, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = texture->addr + ((y * texture->line_len) + (x * texture->bpp / 8));
	color = *(int *)pixel;
	return (color);
}

/*
 * calculates the wall pixel hit position
 */
double	calc_wall_px_hit(t_game *game, int flag)
{
	double	wall_px;

	if (flag == 0)
		wall_px = game->player.p_y + game->ray_distance
			* game->player.ray_dir_y;
	else
		wall_px = game->player.p_x + game->ray_distance
			* game->player.ray_dir_x;
	return (wall_px);
}

/*
 * determines the texture side based on ray direction
 */
t_img	*define_side(t_game *game)
{
	t_img	*texture;

	if (game->flag == 0)
	{
		if (game->ray_angle > PI / 2 && game->ray_angle < 3 * (PI / 2))
			texture = &game->tx_w.img;
		else
			texture = &game->tx_e.img;
	}
	else
	{
		if (game->ray_angle > 0 && game->ray_angle < PI)
			texture = &game->tx_s.img;
		else
			texture = &game->tx_n.img;
	}
	return (texture);
}

/*
 * returns the maximum of two integers
 */
int	int_imax(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

/*
 * clears the game image by setting all pixels to black
 */
void	clear_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < S_H)
	{
		while (x < S_W)
		{
			put_pixel(x, y, 0, game);
			x++;
		}
		x = 0;
		y++;
	}
}
