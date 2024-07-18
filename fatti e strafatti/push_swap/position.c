/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:27:16 by negambar          #+#    #+#             */
/*   Updated: 2024/07/17 10:41:37 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* 
	get position but for the last index'd
*/
int	get_lowest(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
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

/*
	Finds best target position in stack A for element in stack B
*/
static int	get_target(t_stack **a, int b_idx, int t_idx, int t_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < t_idx)
		{
			t_idx = tmp_a->index;
			t_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (t_idx != INT_MAX)
		return (t_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < t_idx)
		{
			t_idx = tmp_a->index;
			t_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (t_pos);
}

/*
	Assigns target positions in stack A for each element in B
				used for cost calculation
*/
void	get_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		t_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	t_pos = 0;
	while (tmp_b)
	{
		t_pos = get_target(a, tmp_b->index, INT_MAX, t_pos);
		tmp_b->t_pos = t_pos;
		tmp_b = tmp_b->next;
	}
}
