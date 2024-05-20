/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:35:41 by negambar          #+#    #+#             */
/*   Updated: 2024/05/20 12:17:21 by negambar         ###   ########.fr       */
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


int		main(int ac, char **av)
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
	dup = malloc(sizeof(int) * (ac - 1));
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
		if (dups(dup, i - 1)
			|| sorted(dup, i - 1))
			return(0);
		size = i - 1;
		b = (stack *)ft_calloc(1, sizeof(stack));
		fill_stack_a(av, size, a);
		push_swap(&a, &b, size);
	}
	// while(a)
	// {
	// 	ft_printf("\n\na:%d\tcost:%d\t\ta->index:%d", a->value, a->cost , a->index);
	// 	a = a->next;
	// }
	// while(b)
	// {
	// 	ft_printf("\n\n\n\nb:%d\tcost:%d\t\tb->index:%d", b->value, b->cost,b->index );
	// 	b = b->next;
	// }
	free_stack(&a);
	free_stack(&b);
}
