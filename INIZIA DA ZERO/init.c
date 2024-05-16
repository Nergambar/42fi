/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:31:41 by negambar          #+#    #+#             */
/*   Updated: 2024/05/16 13:32:11 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_stack_a(char **av, int size, stack *a)
{
	int i = 0;

	while(i <= size)
	{
		if (ft_isdigit(av[i]))
		{
			if (a->value == 0)
			{
				add_nodes(ft_atoimdf(av[i]), &a);// Update the value after adding the node
			}
			else
			{
				tail_add(ft_atoimdf(av[i]), &a);
				a = a->next;
			}
		}
		i++;
	}
}