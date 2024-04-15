/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:57:37 by negambar          #+#    #+#             */
/*   Updated: 2024/04/15 12:56:36 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_free(char **mtx, t_struct *loop)
{
	if (!checkmap(loop, mtx, loop->pos[0], loop->pos[1]))
	{
		write(1, "Error\n[Invalid map]\n", 20);
		clearmtx(loop->matrix);
		clearmtx(mtx);
		free(loop);
		return (1);
	}
	return (0);
}

void	loop_free(t_struct *loop)
{
	write(1, "Error\n[Invalid map]\n", 20);
	free(loop);
}
