/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuttomio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:02:05 by negambar          #+#    #+#             */
/*   Updated: 2024/05/17 11:29:30 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void five(stack **a, stack **b)
{
	int tall;
	int low;

	tall = tallest(*a);
	low = low_value(*a);
	if((*a)->value != tall && (*a)->value != low)
		while ((*a)->value != tall && (*a)->value != low)
			do_ra(a);
	do_pa(a, b);
	if((*a)->value != tall && (*a)->value != low)
		while ((*a)->value != tall && (*a)->value != low)
			do_ra(a);
	do_pa(a, b);
	tiny(a, b);
	if ((*b)->value == tall)
	{	
		do_pb(b, a);
		do_ra(a);
	}
	else
	{
		do_pb(b, a);
		do_pb(b, a);
		do_ra(a);
	}
	do_pb(b, a);
}

void four(stack **a, stack **b)
{
	int low;
	int hi;

	hi = tallest(*a);
	low = low_value(*a);
	printf("low = %d\n", low);
	printf("hi = %d\n", hi);
	if ((*a)->value != hi && (*a)->next->value != low)
		while ((*a)->value != hi && (*a)->next->value != low)
			do_ra(a);
	do_pa(a, b);
	tiny(a, b);
	if ((*b)->value == hi)
	{	
		do_pb(b, a);
		do_ra(a);
	}
	else
	{
		do_pb(b, a);
	}
	if ((*a)->value != low)
		do_ra(a);
}

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