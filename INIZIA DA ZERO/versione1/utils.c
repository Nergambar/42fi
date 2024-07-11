/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:56:52 by negambar          #+#    #+#             */
/*   Updated: 2024/05/28 13:18:25 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int tallest(stack *a)
{
	int i;
	if (!a)
		fterror(2);
	i = a->value;
	while(a)
	{
		if (a->value >= i)
			i = a->value;
		if (!a->next)
			break;
		a = a->next;
	}
	return (i);
}

int low_value(stack *a)
{
	int low;

	low = a->value;
	while(a)
	{
		if(a->value < low)
		{
			low = a->value;
		}
		a = a->next;
	}
	return (low);
}

int nb_abs(int n)
{
	if (n < 0)
		return (-n);
	return(n);
}

int check_number(char *str)
{
	if (ft_strlen(str) >= 13)
	{
		fterror(2);
		return (0);
	}
	return (1);
}

int get_stack_size(stack *s)
{
	int i;

	i = 0;
	if(!s)
		return (0);
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}