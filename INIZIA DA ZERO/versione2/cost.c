/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:26:37 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 14:41:44 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = stack_size(tmp_a);
	size_b = stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
	
}
void do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int 	cheapest;
	int 	cost_a;
	int 	cost_b;

	tmp = *b;
	cheapest = INT_MAX;
	printf("cost_a = %d\n", (*a)->cost_a);
	printf("cost_b = %d\n", (*b)->cost_b);
	printf("tmp->cost_a = %d\n", tmp->cost_a);
	printf("tmp->cost_b = %d\n", tmp->cost_b);
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			printf("cost_a = %d\n", cost_a);
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(a, b, cost_a, cost_b);
}
