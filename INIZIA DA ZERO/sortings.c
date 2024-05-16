/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:10:25 by negambar          #+#    #+#             */
/*   Updated: 2024/05/16 11:54:36 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(stack *a, stack *b, char c)
{
	int tmp;

	if (((!a || (!a->next)) && (!a || !a->next)))
	{
        return;
	}
	if (c == 'a')
	{
		tmp = a->value;
		a->value = a->next->value;
		a->next->value = tmp;
		write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		tmp = b->value;
		b->value = b->next->value;
		b->next->value = tmp;
		write(1, "sb\n", 3);
	}
	else if (c == 's')
	{
		swap(a, b, 'a');
		swap(a, b, 'b');
		write(1, "ss\n", 3);
	}
}

void rotate(stack **a, stack **b, int size, char c)
{
    stack *end;
    stack *tmp;

	end = (stack *)ft_calloc(1, sizeof(stack));
	tmp = NULL;

    if ((!(*a) && !(*a)) || (!(*a)->next && !(*a)->next))
        return;
    if (c == 'a' && *a && (*a)->next)
    {
        tmp = *a;
        (*a)->prev = NULL;
        ft_lstlast(*a);
		end->next = NULL;
        end->next = tmp;
        tmp->prev = end;
        tmp->next = NULL;
		indexes(*a, size);
		write(1, "ra\n", 3);
    }
    if (c == 'b' && *a && (*a)->next)
    {
		tmp = *b;
        (*b) = (*b)->next;
        (*b)->prev = NULL;
        ft_lstlast(*b);
        end->next = tmp;
        tmp->prev = end;
        tmp->next = NULL;
		indexes(*b, size);
		write(1, "rb\n", 3);
    }
	if (c == 'r')
	{
		rotate(a, b, size, 'a');
		rotate(a, b, size, 'b');
	}
}

void rrotate(stack **a, stack **b, int size, char c)
{
	stack *end;
	stack *tmp;

	end = NULL;
	tmp = NULL;
	if ((!(*a) && !(*b)) || (!(*a)->next && !(*b)->next))
        return;
	if (c == 'a' && *a && (*a)->next)
    {
        ft_lstlast(*a); 
        tmp = end->prev;      
        tmp->next = NULL;
        end->next = (*a);
        end->prev = NULL;     
        (*a)->prev = end;
        *a = end;
		indexes(*a, size);
		write(1, "rra\n", 4);
    }
	if (c == 'b' && *b && (*b)->next)
    {
        ft_lstlast(*b);
        tmp = end->prev;      
        tmp->next = NULL;
        end->next = (*b);
        end->prev = NULL;     
        (*b)->prev = end;
        *b = end;
		indexes(*b, size);
    }
	if (c == 'r')
	{
		rrotate(a, b, size, 'a');
		rrotate(a, b, size, 'b');
	}
}

void	push(stack **stack_to, stack **stack_from, int size)
{
	stack	*tmp;
	stack	*head_to;
	stack	*head_from;

	if (size == 0)
		return ;
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	if (head_from)
		head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
}

void	do_pa(stack **stacka_to, stack **stackb_from, int size)
{
	if (!stackb_from)
		return ;
	push(stacka_to, stackb_from, size);
	write(1, "pa\n", 3);
}

void	do_pb(stack **from, stack **to, int size)
{
	if (!from)
		return ;
	push(to, from, size);
	write(1, "pb\n", 3);
}