/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:28:40 by negambar          #+#    #+#             */
/*   Updated: 2024/05/13 15:39:57 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void tiny(list *one)
{
	int hi;

	write(1, "qua prende!\n", 13);
	hi = tallest(one);
	if (one->a->value == hi)
		rotate(&one, 'a');
	else if (one->a->next->value == hi)
		rrotate(&one, 'a');
	if (one->a->value > one->a->next->value)
		swap(one, 'a');
}
void push_swap(list *one, int size)
{
	if (size == 2)
		swap(one, 'a');
	if (size == 3){
		write(1, "qua prende1!\n", 13);
		tiny(one);
}	else if (size == 5)
		five(one);
}