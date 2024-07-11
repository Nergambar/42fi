/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuttomio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:02:05 by negambar          #+#    #+#             */
/*   Updated: 2024/05/28 13:12:25 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void indexes(stack *a, int size)
{
	int j;
	int i;

	i = 0;
	j = size / 2;
	while(a)
	{
		a->index = i;
		if (a->index < j)
			a->middle = true;
		else
			a->middle = false;
		a = a->next;
		i++;
	}
}

void	cost(stack *a, int size)
{
	int j;

	j = size / 2;
	indexes(a, get_stack_size(a));
	while(a)
	{
		if (a->index <= j)
			a->cost = a->index + 1;
		else
			a->cost = size - a->index + 1;
		a = a->next;
	}
}

void post_cost(stack *a, stack *b)
{
	stack *temp = a;

	while (b)
	{
		a = temp;
		while (a)
		{
			if (a->value < b->value)
				b->cost++;
			a = a->next;
		}
		b = b->next;
	}

}