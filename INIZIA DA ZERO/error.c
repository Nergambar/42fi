/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:39:11 by negambar          #+#    #+#             */
/*   Updated: 2024/05/06 17:05:39 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sorted(int *dup, int end)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < end - 1)
	{
		if (dup[i] < dup[i + 1])
			count++;
		i++;
	}
	if (count == end - 1)
		return(1);
	return(0);
}

int dups(int *dup, int end)
{
	int i;
	int j;

	i = 0;
	while(i < end)
	{
		j = i + 1;
		while(j < end)
		{
			if (dup[i] == dup[j])
				return(1);
			j++;
		}
		i++;
	}
	return(0);
}

void	fterror(int i)
{
	if (i <= 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}