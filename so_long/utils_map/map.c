/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:30:48 by negambar          #+#    #+#             */
/*   Updated: 2024/04/05 10:55:22 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_l(char **matrix)
{
	int	i;

	if (!matrix || !matrix[0])
		return (0);
	i = 0;
	while (matrix[1][i] != '\0' && matrix[1][i] != '\n')
		i++;
	return (i);
}

int	get_h(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i] != NULL)
		i++;
	return (i);
}
