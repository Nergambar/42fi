/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:41:54 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 11:49:52 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *s;
	*s = (*s)->next;
	tail = get_stack_bottom(*s);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
void	do_rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}
void	do_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}