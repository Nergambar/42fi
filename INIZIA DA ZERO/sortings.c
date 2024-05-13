/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:10:25 by negambar          #+#    #+#             */
/*   Updated: 2024/05/13 15:13:13 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(list *one, char c)
{
	int tmp;

	if (((!one->a && !one->b) || (!one->a->next)) && (!one->b || !one->b->next))
	{
		printf("ENTRA!!!\n\n\n");
        return;
	}
	if (c == 'a')
	{
		tmp = one->a->value;
		one->a->value = one->a->next->value;
		one->a->next->value = tmp;
		write(1, "sa\n", 3);
		printf("\nNON PUÒ ENTRARE!!!\n\n\n");
	}
	else if (c == 'a')
	{
		printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE!!!\n\n\n");
		tmp = one->b->value;
		one->a->value = one->b->next->value;
		one->b->next->value = tmp;
		write(1, "sb\n", 3);
	}
	else if (c == 's')
	{
		printf("EMOTIONAL DAMAGE!!\n\n\n");
		swap(one, 'a');
		swap(one, 'b');
		write(1, "ss\n", 3);
	}
}

void rotate(list **one, char c)
{
    list *end;
    list *tmp;
	int size;

	end = NULL;
	tmp = NULL;

    if ((!(*one)->a && !(*one)->b) || (!(*one)->a->next && !(*one)->b->next))
        return;
    if (c == 'a' && *one && (*one)->a->next)
    {
		size = get_stack_size(*one);
        tmp = *one;
        *one = (list *)((*one)->a->next);
        (*one)->a->prev = NULL;
        ft_lstlast(*one);
        end->a->next = tmp->a;
        tmp->a->prev = end->a;
        tmp->a->next = NULL;
		indexes(*one);
		write(1, "ra\n", 3);
    }
    if (c == 'b' && *one && (*one)->b->next)
    {
 		size = get_stack_size(*one);
		tmp = *one;
        (*one)->b = (*one)->b->next;
        (*one)->b->prev = NULL;
        ft_lstlast(*one);
        end->b->next = tmp->b;
        tmp->b->prev = end->b;
        tmp->b->next = NULL;
		indexes(*one);
		write(1, "rb\n", 3);
    }
	if (c == 'r')
	{
		rotate(one, 'a');
		rotate(one, 'b');
	}
}

void rrotate(list **one, char c)
{
	list *end;
	list *tmp;
	int size;

	end = NULL;
	tmp = NULL;
	if ((!(*one)->a && !(*one)->b) || (!(*one)->a->next && (!(*one)->b || !(*one)->b->next)))
        return;
	if (c == 'a' && *one && (*one)->a->next)
    {
		size = get_stack_size(*one);
        ft_lstlast(*one); 
        tmp->a = end->a->prev;      
        tmp->a->next = NULL;
        end->a->next = (*one)->a;
        end->a->prev = NULL;     
        (*one)->a->prev = end->a;
        *one = end;
		indexes(*one);
		write(1, "rra\n", 4);
    }
	if (c == 'b' && *one && (*one)->b->next)
    {
		size = get_stack_size(*one);
        ft_lstlast(*one);
        tmp->b = end->b->prev;      
        tmp->b->next = NULL;
        end->b->next = (*one)->b;
        end->b->prev = NULL;     
        (*one)->b->prev = end->b;
        *one = end;
		indexes(*one);
    }
	if (c == 'r')
	{
		rrotate(one, 'a');
		rrotate(one, 'b');
	}
}

void	push(list **stack_to, list **stack_from)
{
	list	*tmp;
	list	*head_to;
	list	*head_from;

	tmp = NULL;
	head_to = NULL;
	head_from = NULL;
	if (get_stack_size(*stack_from) == 0)
		return ;
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	if (head_from)
		head_from->a = head_from->a->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->a->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->a->next = head_to->a;
		*stack_to = tmp;
	}
}

void	do_pa(list *one)
{
	if (!one)
		return ;
	push(&one, &one);
	write(1, "pa\n", 3);
}
void	do_pb(list *one)
{
	if (!one)
		return ;
	push(&one, &one);
	write(1, "pb\n", 3);
}