/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:03:19 by negambar          #+#    #+#             */
/*   Updated: 2023/11/13 12:42:09 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	iszero(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		count = 1;
	}
	return (count);
}

int	ft_print_n(int n)
{
	long	nbl;
	char	c[11];
	int		i;
	int		count;

	i = 0;
	nbl = n;
	count = 0;
	count += iszero(nbl);
	if (nbl < 0)
	{
		nbl = -nbl;
		write (1, "-", 1);
		count++;
	}
	while (nbl > 0)
	{
		c[i++] = (nbl % 10) + '0';
		nbl = nbl / 10;
		count++;
	}
	while (i > 0)
		write (1, &c[--i], 1);
	return (count);
}
