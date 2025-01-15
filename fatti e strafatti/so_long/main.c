/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:52:29 by negambar          #+#    #+#             */
/*   Updated: 2024/04/26 10:33:16 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_close(t_struct **loop)
{
	clearmtx((*loop)->matrix);
	mlx_destroy_image((*loop)->mlx, (*loop)->play);
	mlx_destroy_image((*loop)->mlx, (*loop)->exit);
	mlx_destroy_image((*loop)->mlx, (*loop)->coll);
	mlx_destroy_image((*loop)->mlx, (*loop)->wall);
	mlx_destroy_image((*loop)->mlx, (*loop)->vsp);
	mlx_destroy_window((*loop)->mlx, (*loop)->wi);
	mlx_destroy_display((*loop)->mlx);
	free((*loop)->mlx);
	free((*loop));
	exit(0);
}

int	close_wind(int key, t_struct *loop)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (key == XK_Escape || key == XK_q)
		ft_close(&loop);
	if (key == XK_Up || key == XK_w)
		up(loop);
	if (key == XK_Down || key == XK_s)
		down(loop);
	if (key == XK_Left || key == XK_a)
		left(loop);
	if (key == XK_Right || key == XK_d)
		right(loop);
	return (0);
}

int	main(int ac, char **av)
{
	t_struct	*loop;
	char		**dup;

	if (ac != 2)
		return (1);
	loop = (t_struct *)malloc(sizeof(t_struct));
	if (!checkvalid(loop, av))
		return (1);
	loop->matrix = NULL;
	loop->xy = 0;
	if (valid_map(av) == 0)
		return (loop_free(loop), 1);
	if (!mtx(open(av[1], O_RDONLY), loop))
		return (ft_printf("Error\n[unexpected map found]"), free(loop), 1);
	valid_h_l(loop->matrix, loop);
	dup = mtxdup(loop->matrix);
	loop->moves = 1;
	if (map_free(dup, loop))
		return (1);
	clearmtx(dup);
	all_together(loop, get_l(loop->matrix), get_h(loop->matrix));
	return (0);
}
