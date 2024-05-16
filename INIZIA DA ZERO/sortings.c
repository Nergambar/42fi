/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:10:25 by negambar          #+#    #+#             */
/*   Updated: 2024/05/16 17:19:38 by negambar         ###   ########.fr       */
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
void	rrotate(stack **stack)
{
	stack	*tmp;
	stack	*tail;
	stack	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}


void do_rra(stack **stack_a)
{
	rrotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void do_rrb(stack **stack_b)
{
	rrotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rotate(stack **stac)
{
	stack	*tmp;
	stack	*tail;

	tmp = *stac;
	*stac = (*stac)->next;
	tail = get_stack_bottom(*stac);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	do_rb(stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}


void	push(stack **src, stack **dest)
{
	stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa(stack **stack_b, stack **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	do_pb(stack **stack_a, stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

/* 
void rotate(stack **a, stack **b, char c)
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
		*a = (*a)->next;
		end = get_stack_bottom(*a);
		tmp->next = NULL;
		end->next = tmp;
		write(1, "ra\n", 3);
    }
    if (c == 'b' && *a && (*a)->next)
    {
		tmp = *b;
		*b = (*b)->next;
		end = get_stack_bottom(*b);
		tmp->next = NULL;
		end->next = tmp;
		write(1, "rb\n", 3);
    }
	if (c == 'r')
	{
		rotate(a, b, 'a');
		rotate(a, b, 'b');
	}
} */


/* void rrotate(stack **a, stack **b, int size, char c)
{
	stack *end;
	stack *tmp;

	end = (stack *)malloc(sizeof(stack));
	end = NULL;
	tmp = (stack *)malloc(sizeof(stack));
	tmp = NULL;
	if ((!(*a) && !(*b)) || (!(*a)->next && !(*b)->next))
        return;
	if (c == 'a' && *a && (*a)->next)
    {
        end = ft_lstlast(*a); 
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
        end = ft_lstlast(*b);
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
} */