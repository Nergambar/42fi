/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:21:09 by negambar          #+#    #+#             */
/*   Updated: 2024/04/22 11:13:33 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../so_long.h"
/*#include <stdio.h>*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;

	start = 0;
	len = ft_strlen((char *)s1);
	if (s1 == NULL)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	if (start == len)
	{
		return (ft_strdup(""));
	}
	while (len > 0 && ft_strchr(set, s1[len - 1]))
	{
		len--;
	}
	return (ft_substrrileone(s1, start, len - start));
}
/* char	*ft_strtrim(char *s1, char *set)
{
	size_t	len;
	size_t	start;

	start = 0;
	len = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	if (start == len)
	{
		return (ft_strdup(""));
	}
	while (len > 0 && ft_strchr(set, s1[len - 1]))
	{
		len--;
	}
	return (ft_substr(s1, start, len - start));
} */
/*
int main(int ac, char **av) {
	if (ac == 3)
	{
		char *trimmed_string = ft_strtrim(av[1], av[2]);
		printf("%s\n", trimmed_string);
		free(trimmed_string);
	}
  return 0;
}
*/
