/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:41:15 by negambar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/14 12:19:24 by negambar         ###   ########.fr       */
=======
/*   Updated: 2024/05/06 11:26:02 by negambar         ###   ########.fr       */
>>>>>>> 386f40900f76fde1eaee0bbb768f45023fa70457
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

stack	*ft_lstnew(int content)
{
<<<<<<< HEAD
	stack	*tmp;

	tmp = (stack *)malloc((sizeof(stack)));
	if (!tmp)
		return (NULL);
	tmp->value = content;
	tmp->next = NULL;
	return (tmp);
=======
	stack	*list;

	list = (stack *)malloc((sizeof(*list)));
	if (!list)
		return (NULL);
	list->value = content;
	list->next = NULL;
	return (list);
>>>>>>> 386f40900f76fde1eaee0bbb768f45023fa70457
}
