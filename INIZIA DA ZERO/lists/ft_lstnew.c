/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:41:15 by negambar          #+#    #+#             */
/*   Updated: 2024/05/06 11:26:02 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

stack	*ft_lstnew(int content)
{
	stack	*list;

	list = (stack *)malloc((sizeof(*list)));
	if (!list)
		return (NULL);
	list->value = content;
	list->next = NULL;
	return (list);
}
