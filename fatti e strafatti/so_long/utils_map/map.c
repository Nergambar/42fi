/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:30:48 by negambar          #+#    #+#             */
/*   Updated: 2024/04/22 16:22:52 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_l(char **matrix)
{
	size_t	i;
	size_t	j;
	size_t	n;

	j = 0;
	i = 0;
	if (!matrix || !matrix[j])
		return (0);
	while (matrix[j][i])
		i++;
	n = i;
	while (matrix[j])
	{
		if (ft_strlen(matrix[j]) != n || matrix[j][0] == '\0'
			|| matrix[j][0] == '\n')
			return (0);
		j++;
	}
	return (n);
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
