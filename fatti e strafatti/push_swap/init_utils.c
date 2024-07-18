/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:31:51 by negambar          #+#    #+#             */
/*   Updated: 2024/07/16 13:43:36 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**mtx_dup(char **av)
{
	int		i;
	char	**dup;

	i = 0;
	while (av[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (av[i])
	{
		dup[i] = ft_strdup(av[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

void	free_mtx(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return ;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	new = malloc(sizeof(char) * (size + 1));
	if (!(new))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
