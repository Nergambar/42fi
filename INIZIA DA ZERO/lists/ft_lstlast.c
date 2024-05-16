/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:26:09 by negambar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/16 10:36:40 by negambar         ###   ########.fr       */
=======
/*   Updated: 2024/05/13 14:51:58 by negambar         ###   ########.fr       */
>>>>>>> 386f40900f76fde1eaee0bbb768f45023fa70457
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
stack	*ft_lstlast(stack *lst)
{
	while (lst)
	{
		lst = lst->next;
	}
	return (lst);
=======
void	ft_lstlast(list *lst)
{
	while (lst->a)
	{
		if (!lst->a->next)
		{
			return ;
		}
		lst->a = lst->a->next;
	}
	return ;
>>>>>>> 386f40900f76fde1eaee0bbb768f45023fa70457
}
