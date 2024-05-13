/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:56:52 by negambar          #+#    #+#             */
/*   Updated: 2024/05/13 16:15:57 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int tallest(list *one)
{
	list *tmp;
	int i;

	tmp = one->a;
	i = tmp->a->value;
	while(tmp)
	{
		if (tmp->a->value > i)
			i = tmp->a->value;
		tmp->a = tmp->a->next;
	}
	return (i);
}

int low_value(list *one)
{
	list *tmp;
	int low;

	tmp = one;
	low = INT_MAX;
	while(tmp)
	{
		if(tmp->a->value < low)
		{
			low = tmp->a->value;
		}
		tmp->a = tmp->a->next;
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