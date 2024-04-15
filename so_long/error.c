/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:49:33 by negambar          #+#    #+#             */
/*   Updated: 2024/04/15 12:37:54 by negambar         ###   ########.fr       */
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
	l = get_l(mtx) - 1;
	while (i < h)
	{
		if (mtx[i][0] != '1' || mtx[i][l] != '1')
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
	while ((i < length && mtx[0] != NULL) || (i > length && mtx[0] != NULL))
	{
		if (mtx[0][i] != '1' || mtx[h][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	wall_maria(char **mtx)
{
	if (is_walled2(mtx) && is_walled2(mtx))
		return (1);
	return (0);
}
