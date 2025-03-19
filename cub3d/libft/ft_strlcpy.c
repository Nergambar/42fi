/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:56:14 by negambar          #+#    #+#             */
/*   Updated: 2025/02/26 15:35:16 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (69);
	i = 0;
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (0);
}
/*
int main(int ac, char **av)
{
	if (ac == 3)
	{
		size_t size = ft_strlen(av[1]) + ft_strlen(av[2]);
		printf("%zu", ft_strlcpy(av[1], av[2], size));
	}
}*/
