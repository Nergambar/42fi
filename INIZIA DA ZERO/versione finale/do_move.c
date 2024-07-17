/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:26:19 by negambar          #+#    #+#             */
/*   Updated: 2024/07/17 10:07:08 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	Reverse rotates stack A and B until one of them is in position.
 */
static void	do_rev_rotate_both(t_stack **a, t_stack **b, int *ca, int *cb)
{
	while (*ca < 0 && *cb < 0)
	{
		(*ca)++;
		(*cb)++;
		do_rrr(a, b);
	}
}

static void	do_rotate_both(t_stack **a, t_stack **b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		(*ca)--;
		(*cb)--;
		do_rr(a, b);
	}
}

static void	do_rotate_a(t_stack **a, int *cost)
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

static void	do_rotate_b(t_stack **b, int *cost)
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

void	do_move(t_stack **a, t_stack **b, int ca, int cb)
{
	if (ca < 0 && cb < 0)
		do_rev_rotate_both(a, b, &ca, &cb);
	else if (ca > 0 && cb > 0)
		do_rotate_both(a, b, &ca, &cb);
	do_rotate_a(a, &ca);
	do_rotate_b(b, &cb);
	do_pa(a, b);
}
