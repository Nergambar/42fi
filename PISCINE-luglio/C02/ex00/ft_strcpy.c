/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:08:33 by negambar          #+#    #+#             */
/*   Updated: 2023/09/07 18:08:36 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char
	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int main(void)
{
    char dest[50];
    char src[] = "whinnie the pooh"; 
    ft_strcpy(dest, src);
    printf("%s\n%s", src, dest);

    return 0;
}*/
