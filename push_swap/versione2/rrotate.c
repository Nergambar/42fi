/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:45:38 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 13:09:09 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*be_tail;

	tail = get_stack_bottom(*s);
	be_tail = get_stack_before_bottom(*s);
	tmp = *s;
	*s = tail;
	(*s)->next = tmp;
	be_tail->next = NULL;
}

void	do_rra(t_stack **a)
{
	rev_rotate(a);
	write(1, "rra\n", 3);
}
void	do_rrb(t_stack **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 3);
}
void	do_rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 3);
}