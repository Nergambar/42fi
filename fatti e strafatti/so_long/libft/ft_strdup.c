/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:14:21 by negambar          #+#    #+#             */
/*   Updated: 2024/04/16 12:17:43 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*#include <stdio.h>*/

char	*ft_strdup(char *s)
{
	char	*n;
	int		size;

	size = ft_strlen(s);
	n = malloc(sizeof(char) * (size + 1));
	if (n == NULL)
		return (NULL);
	ft_memcpy(n, s, size);
	return (n);
}
/*
int main(int ac, char **av)
{
	if (ac == 2)
		printf("%s", ft_strdup(av[1]));
}*/
