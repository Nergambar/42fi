/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mtx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:41:14 by negambar          #+#    #+#             */
/*   Updated: 2024/03/23 16:09:02 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "./libft/libft.h"

/* static int get_len(int fd)
{
	char *s;
	int i;

	s = NULL;
	i = 0;
	fd = open("map1.ber", O_RDONLY);
	s = get_next_line(fd);
	while(s[i])
		i++;
	i--;
	return(i);
} */

static int get_high(char **av)
{
	int i;
	char *s;
	int fd;

	s = NULL;
	i = 0;
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		free(s);
		i++;
	}
	close(fd);
	return (i);
}


void mtx(char **av, t_struct *sprites)
{
	int height;
	char *s;
	int i;
	int fd;

	s = NULL;
	fd = open(av[1], O_RDONLY);
	i = 0;
	height = get_high(av);
	sprites->matrix = (char **)malloc(sizeof(char *) * (height + 1));
	if (!sprites->matrix)
		return ;
	s = get_next_line(fd);
	while(s)
	{
		sprites->matrix[i] = ft_strdup(s);
		free(s);
		s = get_next_line(fd);
		if (!sprites->matrix[i])
		clearmtx(sprites->matrix);
		i++;
	}
	free(s);
	sprites->matrix[i] = 0;
	close(fd);
}

/* #include <stdio.h>

int main(int ac, char **av)
{
	int fd = open("map1.ber", O_RDONLY);
	char *s;
	int i;
	char **matx;
	t_struct sprites;

	s = NULL;
	i = 0;
	//s = get_next_line(fd);
	matx = sprites.matrix;
	while(i < 3)
	{
		printf("%s", matx[i]);
		i++;
	}
	return(i);
} */