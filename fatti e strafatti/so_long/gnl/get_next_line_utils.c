/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:44:00 by negambar          #+#    #+#             */
/*   Updated: 2024/04/22 11:11:35 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, char stop_char)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (s == NULL || s[0] == '\0')
		return (NULL);
	len = 0;
	while (s[len] != stop_char && s[len] != '\0')
		len++;
	str = (char *)ft_calloc(((len - start) + 2), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[start] != stop_char && s[start] != '\0')
		str[i++] = s[start++];
	if (s && s[start] == stop_char)
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_substrrileone(char const *s, unsigned int start, unsigned int end)
{
	char	*out;
	int		i;
	int		len;

	len = end - start;
	out = ft_calloc(len + 1, sizeof(char));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		out[i] = s[start];
		start++;
		i++;
	}
	return (out);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (count * size));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
