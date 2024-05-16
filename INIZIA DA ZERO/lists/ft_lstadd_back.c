/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:36:40 by negambar          #+#    #+#             */
/*   Updated: 2024/05/14 12:16:23 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(stack **lst, stack *new)
{
	stack	*tmp;

	tmp = NULL;
	if (lst != NULL && lst[0] != NULL)
	{
		ft_lstlast(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
}
