/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:36:04 by negambar          #+#    #+#             */
/*   Updated: 2024/07/11 13:14:02 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *s)
{
	while (s && s->next)
	{
		if (s->value > s->next->value)
			return (0);
		s = s->next;
	}
	return (1);
}

static void push_swap(t_stack **a, t_stack **b, int size)
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
	t_stack *a;
	t_stack *b;
	int		size;

	if (ac < 2)
		return (0);
	if (!correct(av))
		exit_error(1);
	b = NULL;
	a = fill_stack_value(ac, av);
	size = stack_size(a);
	assign_index(a, size + 1);
	push_swap(&a, &b, size);
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}