/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:31:41 by negambar          #+#    #+#             */
/*   Updated: 2024/05/13 16:14:16 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_stack_a(int ac, char **av, list *one)
{
	int i;

	i = 0;
	while(++i < ac)
	{
		if (ft_isdigit(av[i]))
			add_nodes(ft_atoimdf(av[i]), one);
		else
			fterror(2);
	}
}

int get_stack_size(list *one)
{
	int i;
	stack *temp;

	temp = one->a;
	i = 0;
	if (!temp){
		write(1, "aaaaaaaaaaaaaaa", 16);
		return (0);}
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}