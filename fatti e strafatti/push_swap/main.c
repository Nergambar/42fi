/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:27:08 by negambar          #+#    #+#             */
/*   Updated: 2024/07/17 10:36:36 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		do_sa(a);
	else if (size == 3)
		tiny(a);
	else if (size > 3 && !is_sorted(*a))
		sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (ac < 2 || !correct(av, ac))
		return (0);
	b = NULL;
	a = fill_stack_value(ac, av);
	if (!a)
		return (0);
	size = stack_size(a);
	assign_index(a, size + 1);
	push_swap(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
