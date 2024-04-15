/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:13:57 by negambar          #+#    #+#             */
/*   Updated: 2023/09/07 18:14:01 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char
	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*int main(void)
{
    char dest[] = "World1";
    const char src[] = "Hello";
    unsigned int n;
    n = 3;

    ft_strncpy(dest, src, n);
    printf("%s", dest);

    return 0;
}*/
