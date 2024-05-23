/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:57:58 by negambar          #+#    #+#             */
/*   Updated: 2024/05/23 12:43:21 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void init_list(stack *a)
{
	stack *temp = a;
	if (temp->next->value > temp->value
		&& temp->next->next->value > temp->next->value)
	{
			temp->next->next->flag = true;
			temp->next->flag = true;
			temp->flag = true;
	}
}

static void check_list(stack *a)
{
	stack *temp = a;

	init_list(temp);
	while (temp)
	{
		if (temp->flag == true && temp->next->value > temp->value)
		{
			if (temp->next->value > temp->value
				&& temp->next->next->value > temp->next->value)
			{
				temp->next->next->flag = true;
				temp->next->flag = true;
				temp->flag = true;
			}
		}
		temp = temp->next;
	}
}
static int count_flags(stack *a)
{
	stack *temp = a;
	int count = 0;

	while (temp)
	{
		if (temp->flag == true)
			count++;
		temp = temp->next;
	}
	return (count);
}


void make_list(stack *a, stack *b)
{
	int flags;

	flags = count_flags(a);
	check_list(a);
	while (a)
	{
		while (flags >= 0)
		{
			do_pb(&a, &b);
			flags--;
		}
		do_ra(&a);
	}
}
