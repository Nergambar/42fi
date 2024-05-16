/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:36:06 by negambar          #+#    #+#             */
/*   Updated: 2024/04/22 11:13:14 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*#include <stdio.h>*/

int	copy_string(char **dest, const char *src, int start)
{
	size_t	i;

	i = start;
	while (src[i - start] != '\0')
	{
		*dest[i] = src[i - start];
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	int		len1;
	int		len2;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	out = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!(out))
		return (0);
	while (i < len1)
		out[i++] = *(s1++);
	while (j < len2)
	{
		out[i++] = *(s2++);
		j++;
	}
	out[i] = '\0';
	return (out);
}
/*
int main(int ac, char **av)
{
	if (ac == 3)
	printf("%s", ft_strjoin(av[1], av[2]));
}*/
