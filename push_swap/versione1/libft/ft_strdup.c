/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:14:21 by negambar          #+#    #+#             */
/*   Updated: 2024/05/28 12:22:03 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

char	*ft_strdup(const char *s)
{
	char	*n;
	int		size;

	size = ft_strlen(s) + 1;
	n = malloc(sizeof(char) * size);
	if (n == NULL)
		return (NULL);
	ft_memcpy(n, s, size);
	return (n);
}
