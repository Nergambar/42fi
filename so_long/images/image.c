/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:26:38 by negambar          #+#    #+#             */
/*   Updated: 2024/04/05 10:58:17 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>
#include <stdio.h>

void	image(t_struct *sp)
{
	int	i;

	i = 32;
	sp->flag = 1;
	sp->xy = &i;
	sp->play = mlx_xpm_file_to_image(sp->mlx, PL, sp->xy, sp->xy);
	sp->wall = mlx_xpm_file_to_image(sp->mlx, WA, sp->xy, sp->xy);
	sp->exit = mlx_xpm_file_to_image(sp->mlx, EX, sp->xy, sp->xy);
	sp->coll = mlx_xpm_file_to_image(sp->mlx, CO, sp->xy, sp->xy);
	sp->vsp = mlx_xpm_file_to_image(sp->mlx, VO, sp->xy, sp->xy);
}

void	checker(t_struct *sp, int i, int j)
{
	if (!sp->flag)
		image(sp);
	if (sp->matrix[i][j] != 0 && sp->matrix[i][j] == 'P')
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->play, j *= MAP, i *= MAP);
	else if (sp->matrix[i][j] != 0 && sp->matrix[i][j] == '1')
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->wall, j *= MAP, i *= MAP);
	else if (sp->matrix[i][j] != 0 && sp->matrix[i][j] == 'C')
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->coll, j *= MAP, i *= MAP);
	else if (sp->matrix[i][j] != 0 && sp->matrix[i][j] == 'E')
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->exit, j *= MAP, i *= MAP);
	else if (sp->matrix[i][j] != 0 && sp->matrix[i][j] == '0')
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->vsp, j *= MAP, i *= MAP);
}

int	twindow(t_struct *sp)
{
	int		i;
	int		j;
	char	**dup;

	i = 0;
	j = 0;
	sp->flag = 0;
	while (sp->matrix[i])
	{
		while (sp->matrix[i][j])
		{
			checker(sp, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	dup = mtxdup(sp->matrix);
	if (!dup)
		return (0);
	clearmtx(dup);
	return (1);
}
