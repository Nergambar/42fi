/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:39:11 by negambar          #+#    #+#             */
/*   Updated: 2024/05/23 10:51:18 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fterror(int i);

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
		fterror(1);
	return(0);
}
int sorted_stack(stack *s, int size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (s->value < s->next->value)
			count++;
		i++;
	}
	if (count == size)
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
				fterror(2);
			j++;
		}
		i++;
	}
	return(0);
}

void	fterror(int i)
{
	if (i == 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (i == 1)
	{
		ft_putstr_fd("Error\nSorted", 2);
		exit(EXIT_FAILURE);
	}
}
