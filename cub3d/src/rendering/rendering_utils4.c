/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:08:26 by negambar          #+#    #+#             */
/*   Updated: 2025/03/10 11:55:10 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

/**
 * get_texture_color - Retrieves the color of a specific pixel from a texture.
 * @texture: Pointer to the texture image.
 * @x: X coordinate of the pixel.
 * @y: Y coordinate of the pixel.
 * 
 * Return: The color of the pixel.
 */
int	get_texture_color(t_img *texture, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = texture->addr + ((y * texture->line_len) + (x * texture->bpp / 8));
	color = *(int *)pixel;
	return (color);
}

/**
 * calc_wall_px_hit - Calculates the wall pixel hit position.
 * @game: Pointer to the game structure.
 * @flag: Determines the axis (0 for y-axis, 1 for x-axis).
 * 
 * Return: The wall pixel hit position.
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

/**
 * define_side - Determines the texture side based on the ray angle.
 * @game: Pointer to the game structure.
 * 
 * Return: Pointer to the selected texture image.
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

/**
 * int_imax - Returns the maximum of two integers.
 * @n1: First integer.
 * @n2: Second integer.
 * 
 * Return: The maximum integer.
 */
int	int_imax(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

/**
 * clear_image - Clears the game image by setting all pixels to black.
 * @game: Pointer to the game structure.
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
