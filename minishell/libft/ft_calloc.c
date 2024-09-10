/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:43:54 by negambar          #+#    #+#             */
/*   Updated: 2024/09/10 15:10:57 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < (nmemb * size))
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}
