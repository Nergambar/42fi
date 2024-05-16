/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:21:28 by negambar          #+#    #+#             */
/*   Updated: 2024/05/15 11:49:02 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, char *c)
{
	while (*s != *c && *s)
	{
		s++;
	}
	if (*s == *c)
	{
		return ((char *)s);
	}
	if (*c == '\0')
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>

int main()
{
	printf("%i", ft_strchr("teste", 'e'));
	
}*/
