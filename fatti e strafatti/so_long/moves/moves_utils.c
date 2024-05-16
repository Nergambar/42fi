/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:19:01 by negambar          #+#    #+#             */
/*   Updated: 2024/04/22 15:31:28 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	printmv(int moves)
{
	ft_putnbr(moves);
	ft_putchar('\n');
}

void	closing(t_struct *loop)
{
	printmv(loop->moves++);
	ft_close(&loop);
}
