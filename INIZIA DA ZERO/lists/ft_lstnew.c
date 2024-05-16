/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:41:15 by negambar          #+#    #+#             */
/*   Updated: 2024/05/14 12:19:24 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

stack	*ft_lstnew(int content)
{
	stack	*tmp;

	tmp = (stack *)malloc((sizeof(stack)));
	if (!tmp)
		return (NULL);
	tmp->value = content;
	tmp->next = NULL;
	return (tmp);
}
