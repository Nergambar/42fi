/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:06:42 by negambar          #+#    #+#             */
/*   Updated: 2024/03/25 16:06:08 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **mtxdup(char **mtx)
{
	char **dup;
	int count;

	printmtx(mtx);
	count = get_h(mtx);
	dup = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!dup)
		return(NULL);
	count = 0;
	while(mtx[count])
	{
		dup[count] = ft_strdup(mtx[count]);
		count++;
	}
	return(dup);
}

void checkfill(char **map, int y, int x)
{
	if (map[y][x] == 'X' || map[y][x] == '1')
	{
		return ;
	}
	checkfill(map, y + 1, x);
	checkfill(map, y - 1, x);
	checkfill(map, y, x + 1);
	checkfill(map, y, x - 1);
}
