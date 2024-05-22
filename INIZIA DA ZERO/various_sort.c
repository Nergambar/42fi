/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:28:40 by negambar          #+#    #+#             */
/*   Updated: 2024/05/22 16:00:45 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void tiny(stack **a, stack **b)
{
	int hi;
	int lowest;
	stack *end;

	(void)b;
	end = (stack *)malloc(sizeof(stack));
	end = get_stack_bottom(*a);
	lowest = low_value(*a);
	hi = tallest(*a);
	if ((*a)->next->value == lowest && end->value == hi)
		swap(*a, *b, 'a');
	else if ((*a)->value == hi && end->value == lowest)
	{
		swap(*a, *b, 'a');
		do_rra(a);
	}
	else if ((*a)->value == hi && (*a)->next->value == lowest)
		do_ra(a);
	else if (end->value == lowest)
		do_rra(a);
	else if ((*a)->value == lowest && (*a)->next->value == hi)
	{
		swap(*a, *b, 'a');
		do_ra(a);
	}
}

void push_swap(stack **a, stack **b, int size)
{
	indexes(*a, size);
	if (size == 2)
		swap(*a, *b, 'a');
	if (size == 3)
		tiny(a, b);
	else if (size == 4)
		four(a, b);
	else if (size == 5)
		five(a, b);
	cost(*a, size);
	
}

void lis_sort(stack **a, stack **b, int *dup)
{
	int i;

	i = 0;
	while(*a)
	{
		if ((*a)->value != dup[i])
			do_pb(a, b);
		else
			do_ra(a);
		i++;
	}
}