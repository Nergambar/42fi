/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:28:40 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 08:44:33 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny(stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = tallest(*stack);
	if ((*stack)->value == highest)
		swap(*stack, NULL, 'a');
	else if ((*stack)->next->value == highest)
		do_rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		swap(*stack, NULL, 'a');
}

/* void tiny(stack **a)
{
	int hi;
	int lowest;
	stack *end;


	end = (stack *)malloc(sizeof(stack));
	end = get_stack_bottom(*a);
	lowest = low_value(*a);
	hi = tallest(*a);
	if ((*a)->next->value == lowest && end->value == hi)
		swap(*a, NULL, 'a');
	else if ((*a)->value == hi && end->value == lowest)
	{
		swap(*a, NULL, 'a');
		do_rra(a);
	}
	else if ((*a)->value == hi && (*a)->next->value == lowest)
		do_ra(a);
	else if (end->value == lowest && (*a)->next->value == hi)
		do_rra(a);
	else if ((*a)->value == lowest && (*a)->next->value == hi)
	{
		swap(*a, NULL, 'a');
		do_ra(a);
	}
} */

void push_swap(stack **a, stack **b, int size)
{
	if (size == 2)
		swap(*a, *b, 'a');
	if (size == 3)
		tiny(a);
	else if (size >= 4)
		sort(a, b);
}
static int get_dup_size(int *dup)
{
	int i;

	i = 0;
	while (dup[i])
		i++;
	return (i);
}

void lis_sort(stack **a, stack **b, int *dup)
{
	int i;
	int size;

	size = get_dup_size(dup);
	i = 0;
	while(i < size)
	{
		if ((*a)->value != dup[i])
			do_pb(a, b);
		do_ra(a);
		i++;
	}
}