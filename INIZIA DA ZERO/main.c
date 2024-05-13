/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:35:41 by negambar          #+#    #+#             */
/*   Updated: 2024/05/13 16:13:54 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_nodes(long num, list *one)
{
    stack *new_node;

    if (num >= INT_MAX || num <= INT_MIN)
        fterror(2);
    new_node = (stack *)ft_calloc(1, sizeof(stack));
    if (!new_node)
        return;
    new_node->prev = NULL;
    new_node->value = num;
    new_node->next = NULL;

    if (one->a == NULL) {
        one->a = new_node;
    } else {
        stack *last_node = one->a;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}
void	tail_add(list **one)
{
	stack	*temp;

	if (!one)
	{
		return ;
	}
	temp = (*one)->a;
	if (temp)
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = (stack *)ft_calloc(1, sizeof(stack));
		if (!temp->next)
		{
			return ;
		}
		temp->next->prev = temp;
		temp->next->value = (*one)->a->value;
		temp->next->next = NULL;
	}
}


int		main(int ac, char **av)
{
	list one;
	int i;
	int *dup;
	int size;

	one.b = NULL;
	one.a = NULL;
	i = 0;
	size = 0;
	dup = malloc(sizeof(int) * (ac - 1));
	one.b = NULL;
	if (ac <= 2)
		return(fterror(1), 0);
	if (ac > 2)
	{
		while (av[++i])
		{
			if (!check_number(av[i]))
				fterror(2);
			dup[i - 1] = ft_atoimdf(av[i]);
		}
		if (dups(dup, i - 1) || sorted(dup, i - 1))
			fterror(2);
		i = 0;
		one.b = (stack *)ft_calloc(1, sizeof(*one.a));
		fill_stack_a(ac, av, &one);
		size = get_stack_size(&one);
		indexes(&one);
		printf("%d", size);
		push_swap(&one, size);
		// printf("%d", one.b->value);
	}
	while(one.a)
	{
		ft_printf("\n\na:%d\n", one.a->value);
		one.a = one.a->next;
	}
  	while(one.b)
	{
		ft_printf("\tb:%d\n", one.b->value);
		one.b = one.b->next;
	}
	ft_lstclear(&one.a);
}
