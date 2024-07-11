/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:05:17 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 13:08:19 by negambar         ###   ########.fr       */
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
	}
	return (lowest_pos);
}

static int get_target(t_stack **a, int t_index, int t_pos)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index < t_index)
		{
			t_index = tmp->index;
			t_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (t_pos);
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
		t_pos = get_target(a, tmp->index, INT_MAX);
		tmp->target_pos = t_pos;
		tmp = tmp->next;
	}
}