/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuttomio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:02:05 by negambar          #+#    #+#             */
/*   Updated: 2024/05/22 15:59:08 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void five(stack **a, stack **b)
{
	int tall;
	int low;
	stack *end;

	tall = tallest(*a);
	low = low_value(*a);
	end = get_stack_bottom(*a);
	end->prev = get_stack_before_bottom(*a);
	if (low == (*a)->next->value && tall == end->value && end->value > end->prev->value){
		swap(*a, *b, 'a');
		if (sorted((int *)a, get_stack_size(*a)))
			return ;}
	while ((*a)->value != tall && (*a)->value != low)
		do_ra(a);
	do_pa(a, b);
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
	if ((*b)->value == low)
		do_pb(b, a);
}

void four(stack **a, stack **b)
{
	int low;
	int hi;
	stack *end;

	hi = tallest(*a);
	low = low_value(*a);
	end = get_stack_bottom(*a);
	end->prev = get_stack_before_bottom(*a);/* 
	printf("low = %d\n", low);
	printf("hi = %d\n", hi); */
	if (low == (*a)->next->value && hi == end->value && end->value > end->prev->value)
		return (swap(*a, *b, 'a'));
	while ((*a)->value != hi && (*a)->value != low)
		do_ra(a);
	do_pa(a, b);
	tiny(a, b);
	if ((*b)->value == hi)
	{	
		do_pb(b, a);
		do_ra(a);
	}
	else
		do_pb(b, a);
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

void	cost(stack *a, int size)
{
	int i;
	int j;

	i = 0;
	j = size / 2;
	while(a)
	{
		if (a->index > j)
			a->cost = a->index - j;
		else
			a->cost = a->index;
		a = a->next;
	}
}