/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:27:08 by negambar          #+#    #+#             */
/*   Updated: 2024/07/16 13:59:47 by negambar         ###   ########.fr       */
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

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (size == 3)
		tiny(stack_a);
	else if (size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (ac < 2 || !correct(av, ac))
		return (0);
	stack_b = NULL;
	stack_a = fill_stack_value(ac, av);
	if (!stack_a)
		return (0);
	size = stack_size(stack_a);
	assign_index(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
