/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:55:47 by negambar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/14 12:06:44 by negambar         ###   ########.fr       */
=======
/*   Updated: 2024/05/06 11:23:00 by negambar         ###   ########.fr       */
>>>>>>> 386f40900f76fde1eaee0bbb768f45023fa70457
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(stack **lst, stack *new)
{
<<<<<<< HEAD
	stack	**stack;

	stack = lst;
	new->next = stack[0];
	stack[0] = new;
=======
	stack	**list;

	list = lst;
	new->next = list[0];
	list[0] = new;
>>>>>>> 386f40900f76fde1eaee0bbb768f45023fa70457
}
