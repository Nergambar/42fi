/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearmtx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:19:22 by negambar          #+#    #+#             */
/*   Updated: 2024/04/15 12:55:48 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_map(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		return (0);
	close(fd);
	return (1);
}

int	checkvalid(t_struct *loop, char **av)
{
	if (!loop || !ft_strrchr2(av[1], ".ber"))
	{
		free(loop);
		return (0);
	}
	return (1);
}

void	clearmtx(char **matrix)
{
	int	n;

	n = 0;
	if (!matrix)
		return ;
	while (matrix[n] != NULL)
	{
		if (matrix[n])
			free(matrix[n]);
		n++;
	}
	free(matrix);
}
