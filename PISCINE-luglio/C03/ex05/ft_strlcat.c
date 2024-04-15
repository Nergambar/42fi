/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:53:46 by negambar          #+#    #+#             */
/*   Updated: 2023/09/12 17:27:22 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned short	i;
	unsigned short	m;

	i = 0;
	while (dest[i] && i < size)
		i++;
	m = 0;
	while (src[m] && i + m < size - 1)
	{
		dest[i + m] = src[m];
		m++;
	}
	if (i < size)
		dest[i + m] = '\0';
	while (src[m])
		m++;
	return (i+m);
}

/*int	main(void)
{
	char dest[1000] = "Hello ";
	char *src = "world\n";
	unsigned int result = ft_strlcat(dest, src, 100);

	printf("%s", dest);
	printf("%u\n", result);
	return (0);
}*/
