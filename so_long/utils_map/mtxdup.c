/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:53:46 by negambar          #+#    #+#             */
/*   Updated: 2024/04/05 10:55:50 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**mtxdup(char **mtx)
{
	char	**dup;
	int		count;

	count = get_h(mtx);
	dup = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!dup)
		return (NULL);
	count = 0;
	while (mtx[count])
	{
		dup[count] = ft_strdup(mtx[count]);
		count++;
	}
	return (dup);
}
