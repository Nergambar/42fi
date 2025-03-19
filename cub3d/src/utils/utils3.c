/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:34:10 by negambar          #+#    #+#             */
/*   Updated: 2025/03/08 13:08:34 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

char	**duplicate_double_pointer(char **original)
{
	size_t	i;
	size_t	count;
	char	**duplicate;

	i = -1;
	count = 0;
	while (original && original[count])
		count++;
	duplicate = malloc((count + 1) * sizeof(char *));
	if (!duplicate)
		return (NULL);
	while (++i < count)
	{
		duplicate[i] = ft_strdup(original[i]);
		if (!duplicate[i])
		{
			while (i > 0)
				free(duplicate[--i]);
			free(duplicate);
			return (NULL);
		}
	}
	duplicate[count] = NULL;
	return (duplicate);
}
