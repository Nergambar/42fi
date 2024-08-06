/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:38:29 by negambar          #+#    #+#             */
/*   Updated: 2024/07/11 13:06:54 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_but3(t_stack **a, t_stack **b)
{
	int size;
	int push;
	int i;

	size = stack_size(*a);
	push = 0;
	i = 0;
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			do_pb(a, b);
			push++;
		}
		else
			do_ra(a);
		i++;
	}
	while (size - push > 3)
	{
		do_pb(a, b);
		push++;
	}
}

static void shift(t_stack **a)
{
	int low;
	int size;

	size = stack_size(*a);
	low = get_lowest(a);
	if (low > size/2)
	{
		while (low < size)
		{
			do_rra(a);
			low++;
		}
	}
	else
	{
		while (low > 0)
		{
			do_ra(a);
			low--;
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	push_all_but3(a, b);
	tiny(a);
	while(*b)
	{
		get_target_pos(a, b);
		printf("b->cost_a = %d\n\n\n\n\n", (*b)->cost_a);	
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		shift(a);
}