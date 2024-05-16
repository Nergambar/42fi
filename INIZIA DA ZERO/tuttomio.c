/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuttomio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:02:05 by negambar          #+#    #+#             */
/*   Updated: 2024/05/16 11:52:57 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
/* stack *five(stack *a, stack *b)
{
	long tall;
	long low;

	tall = (long)tallest(a);
	low = (long)low_value(a);
	while (a->value != tall && a->value != low)
		rotate(&a, &b, 'a');
	do_pb(&b, &a);
	while (a->value != tall && a->value != low)
		rotate(&a, &b, 'a');
	do_pb(&b, &a);
	a = tiny(a, b);
	do_pa(&a, &b);
	do_pa(&a, &b);
	if (a->next)
		swap(a, b, 'a');
	rotate(&a, &b, 'a');
	return (a);
} */

void five(stack *a, stack *b, int size)
{
	int tall;
	int low;

	tall = tallest(a);
	low = low_value(a);
	while (a->value != tall && a->value != low)
		rotate(&a, &b, size, 'a');
	push(&b, &a, size);
	while (a->value != tall && a->value != low)
		rotate(&a, &b, size, 'a');
	push(&b, &a, size);
	tiny(a, b, size);
	push(&a, &b, size);
	push(&a, &b, size);
	if (a->next)
		swap(a, b, 'a');
	rotate(&a, &b, size, 'a');
}

void indexes(stack *a, int size)
{
	int j;
	int i;

	i = 0;
	j = size / 2;
	while(a)
	{
		a->index = i;
		if (a->index < j)
			a->middle = true;
		else
			a->middle = false;
		a = a->next;
		i++;
	}
}