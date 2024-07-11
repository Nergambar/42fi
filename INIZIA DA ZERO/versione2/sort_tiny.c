/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:59:14 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 13:39:32 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_index(t_stack *a)
{
	int		highest;

	highest = a->index;
	while (a)
	{
		if (a->index > highest)
			highest = a->index;
		a = a->next;
	}
	return (highest);
}

void	tiny(t_stack **s)
{
	int		highest;

	if (is_sorted(*s))
		return ;
	highest = highest_index(*s);
	if ((*s)->index == highest)
		do_ra(s);
	else if ((*s)->next->index == highest)
		do_rra(s);
	if ((*s)->index > (*s)->next->index)
		do_sa(*s);
}
