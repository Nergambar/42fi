/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:34:01 by negambar          #+#    #+#             */
/*   Updated: 2024/05/28 11:19:18 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rev_rotate_both(stack **a, stack **b, int *cost1, int *cost2)
{
	while (*cost1 < 0 && *cost2 < 0)
	{
		(*cost1)++;
		(*cost2)++;
		do_rrr(a, b);
	}
}


static void	do_rotate_both(stack **a, stack **b, int *cost1, int *cost2)
{
	while (*cost1 > 0 && *cost2 > 0)
	{
		(*cost1)--;
		(*cost2)--;
		do_rr(a, b);
	}
}

static void	do_rotate_a(stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

static void	do_rotate_b(stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

void	do_move(stack **a, stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(b, a);
}