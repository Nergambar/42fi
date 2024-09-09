/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:49:33 by negambar          #+#    #+#             */
/*   Updated: 2024/08/08 18:25:30 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_check(char **mtx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mtx[i])
	{
		while (mtx[i][j] && mtx[i][j] != '\n')
		{
			if (mtx[i][j] != 'E' && mtx[i][j] != 'P' && mtx[i][j] != '0'
				&& mtx[i][j] != 'C' && mtx[i][j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	is_walled2(char **mtx)
{
	int	i;
	int	h;
	int	l;

	i = 0;
	h = get_h(mtx);
	l = get_l(mtx);
	while (i < h)
	{
		if (mtx[i][0] != '1' || mtx[i][l - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_walled(char **mtx)
{
	int	i;
	int	length;
	int	h;

	i = 0;
	length = get_l(mtx);
	h = get_h(mtx) - 1;
	while (i < length || mtx[0] != NULL || (len(mtx[i]) == get_l(mtx)))
	{
		if ((mtx[0][i] != '1' || mtx[h][i] != '1'))
			return (0);
		i++;
	}
	return (1);
}

int	wall_maria(char **mtx)
{
	if (is_walled2(mtx) && is_walled2(mtx))
		return (1);
	else
		write(1, "Error\n[Wall maria is under attack!]", 35);
	return (0);
}

int	valid_h_l(char **mtx, t_struct *loop)
{
	if ((get_h(mtx) < 3 || get_l(mtx) < 5)
		|| (get_h(mtx) < 5 || get_l(mtx) < 3))
	{
		ft_printf("Error\n[length or heigth invalid]");
		clearmtx(mtx);
		free(loop);
		exit(1);
	}
	return (1);
}
