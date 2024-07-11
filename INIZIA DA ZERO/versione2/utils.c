/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:40:37 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 13:58:41 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(int error)
{
	if (error == 1)
		write(1, "Error\nwrong input!\n", 19);
	if (error == 2)
		write(1, "Error\ntmi!\n", 12);
	exit(1);
}

int nb_abs(int nb)
{
	printf("nb1 = %d\n", nb);
	if (nb < 0){
		return (nb * -1);
		printf("nb2 = %d\n", nb);}
	printf("nb3 = %d\n", nb);
	return (nb);
}