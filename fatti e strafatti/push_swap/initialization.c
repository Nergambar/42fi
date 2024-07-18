/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:26:29 by negambar          #+#    #+#             */
/*   Updated: 2024/07/17 10:36:28 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_tablen(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	check_stack(t_stack *a_stack)
{
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = a_stack;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		while (tmp != NULL)
		{
			if (ptr->value == tmp->value)
			{
				exit_error(1);
				return (-1);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
	return (1);
}

static int	add_to_stack(t_stack **stack, char *value)
{
	long int	nb;

	nb = ft_atoi(value);
	if (*stack == NULL)
		*stack = stack_new((int)nb);
	else
		stack_add_bottom(stack, stack_new((int)nb));
	return (1);
}

t_stack	*fill_stack_value(int ac, char **av)
{
	t_stack		*a;
	int			i;
	char		**b;
	int			nb_args;

	a = NULL;
	i = -1;
	if (ac == 2)
	{
		b = ft_split(av[1], ' ');
		nb_args = ft_tablen(b);
	}
	else
	{
		b = mtx_dup(&av[1]);
		nb_args = ac - 1;
	}
	while (++i < nb_args)
		if (!add_to_stack(&a, b[i]))
			return (free_stack(&a), NULL);
	if (check_stack(a) == -1)
		return (free_mtx(b), free_stack(&a), NULL);
	free_mtx(b);
	return (a);
}

void	assign_index(t_stack *a, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		ptr = a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}
