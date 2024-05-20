/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:56:52 by negambar          #+#    #+#             */
/*   Updated: 2024/05/17 12:29:28 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int tallest(stack *a)
{
	stack *tmp;
	int i;
	if (!a)
		fterror(2);
	tmp = a;
	i = a->value;
	while(tmp)
	{
		if (tmp->value >= i)
			i = tmp->value;
		if (!tmp->next)
			break;
		tmp = tmp->next;
	}
	return (i);
}

int low_value(stack *a)
{
	stack *tmp;
	int low;

	tmp = a;
	low = INT_MAX;
	while(tmp)
	{
		if(tmp->value < low)
		{
			low = tmp->value;
		}
		tmp = tmp->next;
	}
	return (low);
}

int nb_abs(int n)
{
	if (n < 0)
		n *= -1;
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
	stack *tmp;
	int i;

	i = 0;
	tmp = s;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}