/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:32:10 by negambar          #+#    #+#             */
/*   Updated: 2024/07/17 10:43:27 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_but3(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			do_pb(a, b);
			pushed++;
		}
		else
			do_ra(a);
		i++;
	}
	while (size - pushed > 3)
	{
		do_pb(a, b);
		pushed++;
	}
}

static void	shift_stack(t_stack **a)
{
	int	lowest_pos;
	int	size;

	size = stack_size(*a);
	lowest_pos = get_lowest(a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			do_rra(a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(a);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	push_all_but3(a, b);
	tiny(a);
	while (*b)
	{
		get_target_pos(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}
