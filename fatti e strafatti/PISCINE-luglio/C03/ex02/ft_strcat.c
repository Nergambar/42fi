/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:37:41 by negambar          #+#    #+#             */
/*   Updated: 2023/09/09 16:37:42 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (dest[i] != '\0')
		i++;
	while (src[m] != '\0')
	{
		dest[i + m] = src[m];
		m++;
	}
	dest[i + m] = '\0';
	return (dest);
}

/*#include <stdio.h>
int	main(void)
{
	char dest[1000] = "Hello ";
	char *src = "world\n";

	ft_strcat(dest, src);

	printf("%s", dest);

	return (0);
}*/
