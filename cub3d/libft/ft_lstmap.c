/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:34:47 by negambar          #+#    #+#             */
/*   Updated: 2025/02/26 15:21:29 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	applico prima la funzione in mapped content per poi
	successivamente eseguirci i controlli, in questo modo
	evito di incorrere in memory leaks.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_lst;
	t_list	*mapped_content;

	new_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		mapped_content = f(lst->content);
		node = ft_lstnew(mapped_content);
		if (!node)
		{
			del(mapped_content);
			ft_lstclear(&new_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
