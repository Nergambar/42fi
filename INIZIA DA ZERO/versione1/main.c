/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:35:41 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 10:10:29 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_nodes(long num, stack **a)
{
    if (num >= INT_MAX || num <= INT_MIN)
        return;
    stack *new_node = (stack *)malloc(sizeof(stack));
    if (new_node == NULL)
		return ;
	new_node = *a;
    new_node->value = num;
    new_node->next = (*a)->next;
    *a = new_node;
}

void tail_add(long num, stack **a)
{
    if (!a)
        return;
    stack *temp = *a;
	temp->next = NULL;
	if (!temp)
	{
		temp = (stack *)malloc(sizeof(stack));
		if (!temp)
			return;
		temp->value = num;
		temp->next = NULL;
		*a = temp;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = (stack *)malloc(sizeof(stack));
		if (!temp->next)
			return;
		temp->next->value = num;
		temp->next->next = NULL;
	}
}


/* int		main(int ac, char **av)
{
	stack *a;
	stack *b;
	int i;
	int *dup;
	int size;

	a = NULL;
	b = NULL;
	a = (stack *)malloc(sizeof(stack));
	if (!a)
		return (0);
	a->value = 0;
	i = 0;
	size = 0;
	dup = (int *)malloc(sizeof(int) * (ac - 1));
	b = NULL;
	if (ac < 2)
		return(fterror(1), 0);
	if (ac == 2)
		return(ft_putstr_fd("not yet\n", 1), 0);
	if (ac > 2)
	{
		while (av[++i])
		{
			if (!check_number(av[i]))
				fterror(2);
			if (ft_atoimdf(av[i]))
				dup[i - 1] = ft_atoimdf(av[i]);
		}
		if (dups(dup, i - 1) || sorted(dup, i - 1))
			return(0);
		size = i - 1;
		fill_stack_a(av, size, a);
		i = 0;
		if (size)
			push_swap(&a, &b, size);
	}
	while(a)
	{
		printf("a:\'%d\'\ta->cost:%d\n", a->value, a->cost);
		a = a->next;
	}
	while(b)
	{
		printf("\tb:\'%d\'\tb->cost:%d\n", b->value, b->cost);
		b = b->next;
	}
	free_stack(&a);
	free_stack(&b);
} */

int	main(int ac, char **av)
{
	stack	*stack_a;
	stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}