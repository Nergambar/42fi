/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuttomio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:02:05 by negambar          #+#    #+#             */
/*   Updated: 2024/05/13 15:20:31 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
/* stack *five(stack *one, stack *one.b)
{
	long tall;
	long low;

	tall = (long)tallest(one.a);
	low = (long)low_value(one.a);
	while (one.a->value != tall && one.a->value != low)
		rotate(&one.a, &one.b, 'one.a');
	do_pb(&one.b, &one.a);
	while (one.a->value != tall && one.a->value != low)
		rotate(&one.a, &one.b, 'one.a');
	do_pb(&one.b, &one.a);
	one.a = tiny(one.a, one.b);
	do_pa(&one.a, &one.b);
	do_pa(&one.a, &one.b);
	if (one.a->next)
		swap(one.a, one.b, 'one.a');
	rotate(&one.a, &one.b, 'one.a');
	return (one.a);
} */

void five(list *one)
{
	int tall;
	int low;

	tall = tallest(one);
	low = low_value(one);
	while (one->a->value != tall && one->a->value != low)
		rotate(&one, 'a');
	do_pb(one);
	while (one->a->value != tall && one->a->value != low)
		rotate(&one, 'a');
	do_pb(one);
	tiny(one);
	do_pa(one);
	do_pa(one);
	if (one->a->next)
		swap(one, 'a');
	rotate(&one, 'a');
}


void indexes(list *one)
{
	int j;
	int i;

	i = 0;
	j = get_stack_size(one) / 2;
	while(one->a)
	{
		one->a->index = i;
		if (one->a->index < j)
			one->a->middle = true;
		else
			one->a->middle = false;
		one->a = one->a->next;
		i++;
	}
}