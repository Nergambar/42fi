/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:19:09 by negambar          #+#    #+#             */
/*   Updated: 2024/04/23 14:40:55 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_for_player(t_struct *sp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (sp->matrix[j])
	{
		i = 0;
		while (sp->matrix[j][i])
		{
			if (sp->matrix[j][i] == 'P')
			{
				sp->pos[0] = i;
				sp->pos[1] = j;
			}
			i++;
		}
		j++;
	}
}

void	up(t_struct *sp)
{
	int	i;
	int	j;

	check_for_player(sp);
	i = sp->pos[0];
	j = sp->pos[1];
	if (sp->matrix[j - 1][i] == 'C'
		|| sp->matrix[j - 1][i] == '0' || sp->matrix[j - 1][i] == 'E')
	{
		if (sp->matrix[j - 1][i] == 'C')
			sp->collcount--;
		j -= 1;
		if (sp->matrix[j][i] == 'E' && sp->collcount == 0)
			closing(sp);
		else if (sp->matrix[j][i] == 'E' && sp->collcount != 0)
			return ;
		sp->matrix[j + 1][i] = '0';
		sp->matrix[j][i] = 'P';
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->play, i * 32, j * 32);
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->vsp, i * 32, (j + 1) * 32);
		printmv(sp->moves++);
	}
}

void	down(t_struct *sp)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	check_for_player(sp);
	i = sp->pos[0];
	j = sp->pos[1];
	if (sp->matrix[j + 1][i] == 'C'
		|| sp->matrix[j + 1][i] == '0' || sp->matrix[j + 1][i] == 'E')
	{
		if (sp->matrix[j + 1][i] == 'C')
			sp->collcount--;
		j += 1;
		if (sp->matrix[j][i] == 'E' && sp->collcount == 0)
			closing(sp);
		else if (sp->matrix[j][i] == 'E' && sp->collcount != 0)
			return ;
		sp->matrix[j - 1][i] = '0';
		sp->matrix[j][i] = 'P';
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->play, i * 32, j * 32);
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->vsp, i * 32, (j - 1) * 32);
		printmv(sp->moves++);
	}
}

void	left(t_struct *sp)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	check_for_player(sp);
	i = sp->pos[0];
	j = sp->pos[1];
	if (sp->matrix[j][i - 1] == 'C'
		|| sp->matrix[j][i - 1] == '0' || sp->matrix[j][i - 1] == 'E')
	{
		if (sp->matrix[j][i - 1] == 'C')
			sp->collcount--;
		i -= 1;
		if (sp->matrix[j][i] == 'E' && sp->collcount == 0)
			closing(sp);
		else if (sp->matrix[j][i] == 'E' && sp->collcount != 0)
			return ;
		sp->matrix[j][i + 1] = '0';
		sp->matrix[j][i] = 'P';
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->play, i * 32, j * 32);
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->vsp, (i + 1) * 32, j * 32);
		printmv(sp->moves++);
	}
}

void	right(t_struct *sp)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	check_for_player(sp);
	i = sp->pos[0];
	j = sp->pos[1];
	if (sp->matrix[j][i + 1] == 'C'
		|| sp->matrix[j][i + 1] == '0' || sp->matrix[j][i + 1] == 'E')
	{
		if (sp->matrix[j][i + 1] == 'C')
			sp->collcount--;
		i += 1;
		if (sp->matrix[j][i] == 'E' && sp->collcount == 0)
			closing(sp);
		else if (sp->matrix[j][i] == 'E' && sp->collcount != 0)
			return ;
		sp->matrix[j][i - 1] = '0';
		sp->matrix[j][i] = 'P';
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->play, i * 32, j * 32);
		mlx_put_image_to_window(sp->mlx, sp->wi, sp->vsp, (i - 1) * 32, j * 32);
		printmv(sp->moves++);
	}
}
