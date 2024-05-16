/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:44:27 by negambar          #+#    #+#             */
/*   Updated: 2024/05/13 15:20:50 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len(unsigned long n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	writehex(unsigned long n, const char format)
{
	if (n >= 16)
	{
		writehex(n / 16, format);
		writehex(n % 16, format);
	}
	else
	{
		if (n <= 9)
		{
			ft_putchar(n + '0');
		}
		else
		{
			if (format == 'x')
			{
				ft_putchar(n - 10 + 'a');
			}
			if (format == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned long num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		writehex(num, format);
	return (len(num));
}
