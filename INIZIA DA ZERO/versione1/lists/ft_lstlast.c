/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:26:09 by negambar          #+#    #+#             */
/*   Updated: 2024/05/28 11:35:38 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

stack	*ft_lstlast(stack *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

stack	*get_stack_bottom(stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

stack	*get_stack_before_bottom(stack *s)
{
	while (s && s->next && s->next->next != NULL)
		s = s->next;
	return (s);
}
