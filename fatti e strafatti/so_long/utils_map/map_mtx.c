/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mtx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:41:14 by negambar          #+#    #+#             */
/*   Updated: 2024/04/23 11:08:08 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_next2(int fd)
{
	char	*s;
	char	*tmp;

	s = get_next_line(fd);
	tmp = ft_strtrim(s, "\n");
	free (s);
	return (tmp);
}

int	mtx(int fd, t_struct *loop)
{
	char	*maplines;
	char	*line;

	maplines = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (1)
	{
		if (line[0] == '\0' || line[0] == '\n' || ft_strlen(line) == 0)
		{
			free(line);
			ft_printf("Error\n[Check the file!]\n");
			exit(1);
		}
		maplines = ft_join_free(maplines, line);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	loop->matrix = ft_split(maplines, '\n');
	free(maplines);
	return (1);
}
