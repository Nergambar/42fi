/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:52:29 by negambar          #+#    #+#             */
/*   Updated: 2024/03/25 15:40:19 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int ft_close(t_struct **loop)
{
	//printf("*loop->mtx[0]= %s", (*loop)->matrix[0]);
	clearmtx((*loop)->matrix);
	mlx_destroy_image((*loop)->mlx, (*loop)->player);
	mlx_destroy_image((*loop)->mlx, (*loop)->exit);
	mlx_destroy_image((*loop)->mlx, (*loop)->coll);
	mlx_destroy_image((*loop)->mlx, (*loop)->wall);
	mlx_destroy_window((*loop)->mlx, (*loop)->win);
	mlx_destroy_display((*loop)->mlx);
	free((*loop)->mlx);
	free((*loop));
	exit(0);
}

int close_wind(int key, t_struct *loop)
{
	printf("%d\n", key);
	if (key == 65307)
		ft_close(&loop);
	if (key == XK_Up || key == 119)
		up(loop);
	if (key == XK_Down || key == 115)
		down(loop);
	if (key == XK_Left || key == 97)
		left(loop);
	if (key == XK_Right || key == 100)
		right(loop);
	return (0);
}

void printmtx(char **mtx)
{
	int i = 0;

	while(mtx[i])
	{
		printf("i = %d\n '%s'\n", i, mtx[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	(void)ac;
	t_struct *loop;

	loop = (t_struct *)malloc(sizeof(t_struct));
	if (!loop)
		return (EXIT_FAILURE);
	loop->matrix = NULL;
	loop->xy = 0;
	mtx(av, loop);
	int i = get_l(loop->matrix); //x len
	int j = get_h(loop->matrix); //y len
	loop->mlx = mlx_init();
	loop->win = mlx_new_window(loop->mlx, (i * 32), (j * 32), "it's been so long?");
	twindow(loop);
	printf("che cosa c'e che non vaaaaaaaaa\n\n\n\n");
	mlx_hook(loop->win, 17, 1L<<17, ft_close,&loop);
	mlx_key_hook(loop->win, close_wind, loop);
	mlx_loop(loop->mlx);
	return(0);
}