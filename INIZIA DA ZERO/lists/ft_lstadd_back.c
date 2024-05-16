/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:36:40 by negambar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/14 12:16:23 by negambar         ###   ########.fr       */
=======
/*   Updated: 2024/05/13 14:59:05 by negambar         ###   ########.fr       */
>>>>>>> 386f40900f76fde1eaee0bbb768f45023fa70457
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void	ft_lstadd_back(stack **lst, stack *new)
{
	stack	*tmp;
=======
void	ft_lstadd_back(list **lst, list *new)
{
	list	*tmp;
>>>>>>> 386f40900f76fde1eaee0bbb768f45023fa70457

	tmp = NULL;
	if (lst != NULL && lst[0] != NULL)
	{
		ft_lstlast(*lst);
<<<<<<< HEAD
		tmp->next = new;
=======
		tmp->a->next = new->a;
>>>>>>> 386f40900f76fde1eaee0bbb768f45023fa70457
	}
	else
		*lst = new;
}
