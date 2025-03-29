/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:17:09 by negambar          #+#    #+#             */
/*   Updated: 2025/03/24 15:51:23 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= S_W || y >= S_H || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->img.addr[index] = color & 0xFF;
	game->img.addr[index + 1] = (color >> 8) & 0xFF;
	game->img.addr[index + 2] = (color >> 16) & 0xFF;
}

void	put_pixel2(int x, int y, int *color, t_game *game)
{
	int	index;

	if (x >= S_W || y >= S_H || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color[0];
	game->data[index + 1] = color[1];
	game->data[index + 2] = color[2];
}

int	num_len(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_strnlen(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i <= n)
		i++;
	return (i);
}
