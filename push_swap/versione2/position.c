/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:05:17 by negambar          #+#    #+#             */
/*   Updated: 2024/07/11 13:05:16 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void 	get_pos(t_stack **s)
{
	t_stack	*tmp;
	int 	pos;

	tmp = *s;
	pos = 0;
	while (tmp)
	{
		tmp->pos = pos;
		tmp = tmp->next;
		pos++;
	}
}

int get_lowest(t_stack **s)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *s;
	lowest_index = INT_MAX;
	get_pos(s);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

static int	get_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void get_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		t_pos;

	tmp = *b;
	get_pos(a);
	get_pos(b);
	t_pos = 0;
	while (tmp)
	{
		t_pos = get_target(a, tmp->index, INT_MAX, t_pos);
		tmp->target_pos = t_pos;
		tmp = tmp->next;
	}
}