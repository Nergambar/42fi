/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:31:41 by negambar          #+#    #+#             */
/*   Updated: 2024/05/20 12:15:50 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_stack_a(char **av, int size, stack *a)
{
	int i = 0;

	while(i <= size)
	{
		if (ft_isdigit(av[i]) && a)
		{
			if (i == 1)
			{
				add_nodes(ft_atoimdf(av[i]), &a);
				a->flag = true;
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

void	free_stack(stack **s)
{
	stack	*tmp;

	if (!s || !(*s))
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
	*s = NULL;
}