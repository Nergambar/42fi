/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:30:48 by negambar          #+#    #+#             */
/*   Updated: 2024/03/19 11:44:45 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_l(char **matrix)
{
	int i;

	i = 0;
	while(matrix[1][i] != '\0' && matrix[1][i] != '\n')
		i++; 	
	return(i);
}

int get_h(char **matrix)
{
	int i;

	i = 0;
	while(matrix[i])
		i++;
	return (i);
}
/* 

int main(int ac, char **av)
{
	int i;
	int fd;
	i = 0;
	printf("%d\n%d", get_h(av), get_l(av));
} */