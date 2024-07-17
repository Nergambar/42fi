/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:32:10 by negambar          #+#    #+#             */
/*   Updated: 2024/07/13 17:43:58 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	size;

	size = stack_size(*stack_a);
	lowest_pos = get_lowest(stack_a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
