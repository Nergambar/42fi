/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:12:15 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 11:48:51 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_stack_bottom(t_stack *s)
{
	while (s && s->next != NULL)
		s = s->next;
	return (s);
}

t_stack *get_stack_before_bottom(t_stack *s)
{
	while (s && s->next && s->next->next)
		s = s->next;
	return (s);
}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	stack_add_bottom(t_stack **s, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*s)
	{
		*s = new;
		return ;
	}
	tail = get_stack_bottom(*s);
	tail->next = new;
}

int	stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}