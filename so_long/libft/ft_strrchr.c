/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:39:16 by negambar          #+#    #+#             */
/*   Updated: 2024/04/05 11:55:42 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../so_long.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s);
		i--;
	}
	return (NULL);
}

int	ft_strrchr2(char *s, char *c)
{
	int	s_len;
	int	c_len;
	int	i;
	int	j;

	s_len = ft_strlen(s);
	c_len = ft_strlen(c);
	i = s_len - 1;
	while (i >= 0 && c_len > 0)
	{
		if (s[i] == c[0])
		{
			j = 1;
			while (j < c_len && i + j < s_len && s[i + j] == c[j])
				j++;
			if (j == c_len && i + j == s_len)
				return (1);
		}
		i--;
	}
	write(1, "invalid map! check the .ber ext and the path!\n", 46);
	return (0);
}
