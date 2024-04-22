/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:01:10 by negambar          #+#    #+#             */
/*   Updated: 2024/04/19 17:42:17 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_graphics(t_struct *loop, int x, int y)
{
	loop->mlx = mlx_init();
	loop->wi = mlx_new_window(loop->mlx, x, y, "it's been so_long");
}

void	events(t_struct *loop)
{
	mlx_hook(loop->wi, 17, 1L << 17, ft_close, &loop);
	mlx_key_hook(loop->wi, close_wind, loop);
	mlx_loop(loop->mlx);
}

void	all_together(t_struct *loop, int x, int y)
{
	init_graphics(loop, (x * 32), (y * 32));
	twindow(loop);
	events(loop);
}
