/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:06:24 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 13:35:15 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *fill_stack_value(int ac, char **av)
{
	t_stack		*a;
	long int	nb;
	int			i;

	a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(2);
		if (i == 1)
			a = stack_new((int)nb);
		else
			stack_add_bottom(&a, stack_new((int)nb));
		i++;
	}
	return (a);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*p;
	t_stack	*highest;
	int		value;

	while (stack_size-- > 0)
	{
		p = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (p)
		{
			if (p->value == INT_MIN && p->index == 0)
				p->index = 1;
			if (p->value > value && p->index == 0)
			{
				value = p->value;
				highest = p;
				p = stack_a;
			}
			else
				p = p->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}