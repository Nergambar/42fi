/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:32:59 by negambar          #+#    #+#             */
/*   Updated: 2024/07/11 12:57:31 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void do_rrboth(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

static void do_rboth(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

static void do_rotatea(t_stack **a, int *cost)
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

static void do_rotateb(t_stack **b, int *cost)
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

void do_move(t_stack **a, t_stack **b, int ca, int cb)
{
	if (ca < 0 && cb < 0)
		do_rrboth(a, b, &ca, &cb);
	else if (ca > 0 && cb > 0)
		do_rboth(a, b, &ca, &cb);
	do_rotatea(a, &ca);
	do_rotateb(b, &cb);
	do_pa(a, b);
}