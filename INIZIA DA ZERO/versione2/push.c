/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:51:29 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 14:18:14 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	do_pa(t_stack **a, t_stack **b)
{
	printf("entraaaaaaaaaaaaaaaa\n");
	push(a, b);
	write(1, "pa\n", 3);
}
void	do_pb(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}