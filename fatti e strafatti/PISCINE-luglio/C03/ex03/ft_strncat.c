/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:35:04 by negambar          #+#    #+#             */
/*   Updated: 2023/09/09 16:35:06 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	m;

	i = 0;
	m = 0;
	while (dest[i] != '\0')
		i++;
	while (m < nb && src[m] != '\0')
	{
		dest[i] = src[m];
		i++;
		m++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>
int	main(void)
{
	char dest[1000] = "Hello ";
	char *src = "world\n";

	ft_strncat(dest, src, 3);

	printf("%s", dest);

	return (0);
}*/
