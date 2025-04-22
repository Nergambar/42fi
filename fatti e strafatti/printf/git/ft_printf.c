/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:35 by negambar          #+#    #+#             */
/*   Updated: 2025/04/04 12:24:07 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_formats(va_list arg, const char format)
{
	int		pril;

	pril = 0;
	if (format == 'c')
		pril += ft_print_c(va_arg(arg, int));
	else if (format == 's')
		pril += ft_print_s(va_arg(arg, char *));
	else if (format == 'p')
		pril += ft_print_ptr(va_arg(arg, unsigned long long));
	else if (format == 'd' || format == 'i')
		pril += ft_print_n(va_arg(arg, int));
	else if (format == 'u')
		pril += ft_print_u(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		pril += ft_print_hex(va_arg(arg, unsigned int), format);
	else if (format == '%')
		pril += ft_print_perc();
	return (pril);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;
	int		pril;

	i = 0;
	pril = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			pril += ft_formats(arg, format[i + 1]);
			i++;
		}
		else
			pril += ft_print_c(format[i]);
		i++;
	}
	va_end(arg);
	return (pril);
}

int main()
{
	ft_printf("%d", "ciao", "bao");
}