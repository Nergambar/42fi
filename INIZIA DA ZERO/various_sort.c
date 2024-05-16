/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:28:40 by negambar          #+#    #+#             */
/*   Updated: 2024/05/16 11:54:43 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void tiny(stack *a, stack *b, int size)
{
	int hi;

	write(1, "qua prende!\n", 13);
	hi = tallest(a);
	printf("hi:::%d", hi);
	if (a->value == hi)
		rotate(&a, &b, size, 'a');
	else if (a->next->value == hi)
		rrotate(&a, &b, size, 'a');
	if (a->next != NULL && a->value > a->next->value)
		swap(a, b, 'a');
}

void push_swap(stack *a, stack *b, int size)
{
	if (size == 2)
		swap(a, b, 'a');
	if (size == 3)
	{
		tiny(a, b, size);
	}
	else if (size == 5)
		five(a, b, size);
}