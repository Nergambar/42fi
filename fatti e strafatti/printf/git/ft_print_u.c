/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:25:42 by negambar          #+#    #+#             */
/*   Updated: 2023/11/15 15:45:50 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_print_u(unsigned int n)
{
	long	nbl;
	char	c[11];
	int		i;
	int		count;

	i = 0;
	nbl = n;
	count = 0;
	count += iszero(nbl);
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
