/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:31:41 by negambar          #+#    #+#             */
/*   Updated: 2024/05/16 12:45:05 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_stack_a(char **av, int size, stack *a)
{
	int i;

	i = 0;
	a->value = 0;
	printf("size::%d\n", size);
	printf("i::%d\n", i);
	while(i < size)
	{
		if (a)
		{
			if (ft_isdigit(av[i]))
			{
				if (a->value == 0)
				{
					printf("entrato\n");
					add_nodes(ft_atoimdf(av[i]), &a);
				}
				else
				{
					printf("entrato2\n");
					tail_add(ft_atoimdf(av[i]) , &a);
				}
			}
		}
		printf("%d < %d\n", i , size);
		i++;
	}
}

