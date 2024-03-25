/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:19:09 by negambar          #+#    #+#             */
/*   Updated: 2024/03/25 15:34:00 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_for_player(t_struct *sprites)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(sprites->matrix[j])
	{
		i = 0;
		while(sprites->matrix[j][i])
		{
			if (sprites->matrix[j][i] == 'P')
			{
				sprites->pos[0] = i;
				sprites->pos[1] = j;
			}
			i++;
		}
		j++;
	}
}

void up(t_struct *sprites)
{
	int	i;
	int	j;

	check_for_player(sprites);
	i = sprites->pos[0];
	j = sprites->pos[1];
	// printf("percheeeeeeeeeeeeeeeeeeeeee %d", j);
	if (sprites->matrix[j - 1][i] == 'C' || sprites->matrix[j - 1][i] == '0')
	{
		j -= 1;
		sprites->matrix[j + 1][i] = '0';
		sprites->matrix[j][i] = 'P';
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->player, i * 32, j * 32);
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->voidsp, i * 32, (j + 1) * 32);
	}
}

void down(t_struct *sprites)
{
	int j;
	int i;

	j = 0;
	i = 0;
	check_for_player(sprites);
	i = sprites->pos[0];
	j = sprites->pos[1];
	if (sprites->matrix[j + 1][i] == 'C' || sprites->matrix[j + 1][i] == '0')
	{
		j += 1;
		sprites->matrix[j - 1][i] = '0';
		sprites->matrix[j][i] = 'P';
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->player, i * 32, j * 32);
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->voidsp, i * 32, (j - 1) * 32);
	}
}

void left(t_struct *sprites)
{
	int j;
	int i;

	j = 0;
	i = 0;
	check_for_player(sprites);
	i = sprites->pos[0];
	j = sprites->pos[1];
	if (sprites->matrix[j][i - 1] == 'C' || sprites->matrix[j][i - 1] == '0')
	{
		i -= 1;
		sprites->matrix[j][i + 1] = '0';
		sprites->matrix[j][i] = 'P';
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->player, i * 32, j * 32);
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->voidsp, (i + 1) * 32, j * 32);
	}
}

void right(t_struct *sprites)
{
	int j;
	int i;

	j = 0;
	i = 0;
	check_for_player(sprites);
	i = sprites->pos[0];
	j = sprites->pos[1];
	if (sprites->matrix[j][i + 1] == 'C' || sprites->matrix[j][i + 1] == '0')
	{
		i += 1;
		sprites->matrix[j][i - 1] = '0';
		sprites->matrix[j][i] = 'P';
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->player, i * 32, j * 32);
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->voidsp, (i - 1) * 32, j * 32);
	}
}