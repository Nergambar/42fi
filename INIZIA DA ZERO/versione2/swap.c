/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:53:46 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 13:09:34 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *s)
{
	int	tmp;

	if (!s || !s->next)
		return ;
	tmp = s->value;
	s->value = s->next->value;
	s->next->value = tmp;
	tmp = s->index;
	s->index = s->next->index;
	s->next->index = tmp;
}
void	do_sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}
void	do_sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}
void	do_ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}