/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:43:55 by negambar          #+#    #+#             */
/*   Updated: 2024/05/14 12:08:40 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

int	ft_isdigit(char *s)
{
	int i;

	i = -1;
	while(s[++i]) 
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	return (1);
}
/*  || (s[0] != '-' && s[0] != '+')
int main(int ac, char **av)
{
	if (ac == 2)
	printf("%d", ft_isdigit(*av[1]));
}*/