/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:26:09 by negambar          #+#    #+#             */
/*   Updated: 2024/05/13 14:51:58 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
}
