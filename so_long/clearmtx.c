/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearmtx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:19:22 by negambar          #+#    #+#             */
/*   Updated: 2024/03/22 12:22:46 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void clearmtx(char **matrix)
{
	int n;

	n = 0;
	if (matrix)
		return ;
	while (matrix[n] != NULL)
	{
		if (matrix[n])
			free(matrix[n]);
		n++;
	}
	free(matrix);
}