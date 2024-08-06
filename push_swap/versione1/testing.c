/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:01:54 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 09:19:02 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_but3(stack **stack_a, stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	ft_printf("pushed:%d\n", pushed);
	ft_printf("stack_size:%d\n", stack_size);
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		stack_size = get_stack_size(*stack_a);
		pushed++;
	}
}

static void	shift_stack(stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	printf("shift_stack\n");
	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
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

void	sort(stack **stack_a, stack **stack_b)
{
	push_all_but3(stack_a, stack_b);
	tiny(stack_a);
	while (*stack_b)
	{
		printf("size of b:%d", get_stack_size(*stack_b));
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}