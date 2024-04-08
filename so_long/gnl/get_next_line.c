/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:03:28 by negambar          #+#    #+#             */
/*   Updated: 2024/04/04 16:03:47 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) + 1;
	str = (char *)ft_calloc((j), sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_join_free(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	str = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free (s1);
	return (str);
}

char	*ft_str(char *s)
{
	int		slen;
	int		tlen;
	char	*buf;

	if (s == NULL)
		return (NULL);
	slen = 0;
	tlen = ft_strlen(s);
	while ((s[slen]) != '\n' && (s[slen]))
		slen++;
	if (s[slen] == '\0')
	{
		free (s);
		return (NULL);
	}
	buf = (char *)ft_calloc((tlen - slen + 2), sizeof(char));
	if (!buf)
		return (NULL);
	tlen = 0;
	while (s[slen + 1] != '\0')
		buf[tlen++] = s[(slen++) + 1];
	buf[tlen + 1] = '\0';
	free (s);
	return (buf);
}

char	*ft_get_line(int fd, char *buffer, char *nextl)
{
	int	read_check;

	read_check = 1;
	while (read_check > 0)
	{
		read_check = read(fd, buffer, BUFFER_SIZE);
		if (read_check == -1)
		{
			if (nextl != NULL)
				free(nextl);
			return (NULL);
		}
		if (read_check == 0)
			break ;
		buffer[read_check] = '\0';
		nextl = ft_join_free(nextl, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (nextl);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*nextl = NULL;
	char		*buffer;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (nextl != NULL)
			free (nextl);
		return (NULL);
	}
	res = NULL;
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	nextl = ft_get_line(fd, buffer, nextl);
	free (buffer);
	buffer = NULL;
	res = ft_substr(nextl, 0, '\n');
	nextl = ft_str(nextl);
	return (res);
}
