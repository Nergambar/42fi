/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:26:38 by negambar          #+#    #+#             */
/*   Updated: 2024/03/25 15:41:58 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

void image(t_struct *sprites)
{
	int i;

	i = 32;
	sprites->xy = &i;
	sprites->player = mlx_xpm_file_to_image(sprites->mlx, PLAYER, sprites->xy, sprites->xy);
	sprites->wall = mlx_xpm_file_to_image(sprites->mlx, WALL, sprites->xy, sprites->xy);
	sprites->exit = mlx_xpm_file_to_image(sprites->mlx, EXIT, sprites->xy, sprites->xy);
	sprites->coll = mlx_xpm_file_to_image(sprites->mlx, COLL, sprites->xy, sprites->xy);
	sprites->voidsp = mlx_xpm_file_to_image(sprites->mlx, VOID, sprites->xy, sprites->xy);
}

void checker(t_struct *sprites, int i, int j)
{
	image(sprites);
	if (sprites->matrix[i][j] != 0 && sprites->matrix[i][j] == 'P')
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->player, j *= SIZEMAP, i *= SIZEMAP);
	else if (sprites->matrix[i][j] != 0 && sprites->matrix[i][j] == '1')
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->wall, j *= SIZEMAP, i *= SIZEMAP);
	else if (sprites->matrix[i][j] != 0 && sprites->matrix[i][j] == 'C')
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->coll, j *= SIZEMAP, i *= SIZEMAP);
	else if (sprites->matrix[i][j] != 0 && sprites->matrix[i][j] == 'E')
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->exit, j *= SIZEMAP, i *= SIZEMAP);
	else if (sprites->matrix[i][j] != 0 && sprites->matrix[i][j] == '0')
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->voidsp, j *= SIZEMAP, i *= SIZEMAP);
}

void twindow(t_struct *sprites)
{
	int i;
	int j;
	char **dup;
	i = 0; //y
	j = 0; //x
	while(sprites->matrix[i])
	{
		while(sprites->matrix[i][j])
		{
			checker(sprites, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	dup = mtxdup(sprites->matrix);
	if (!dup)
		return; 
	check_for_player(sprites);
	checkfill(dup, sprites->pos[1], sprites->pos[0]);
	while(dup[i])
	{
		while(dup[i][j])
		{
			if (dup[i][j] != '1' || dup[i][j] != 'X')
			{
				return ;
			}
			else
			{
				printf("udhscfjk%c", dup[i][j]);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
