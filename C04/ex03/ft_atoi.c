/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:22:19 by negambar          #+#    #+#             */
/*   Updated: 2023/09/13 09:22:22 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str);

int main()
{
	char *s = "    -1234/ab567";

	printf("%d", ft_atoi(s));
}

int	ft_atoi(char *str)
{
	short	parity;
	int		number;

	parity = 0;
	number = 0;
	while (*str == 32)
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			write(1, '-', 1);
			break;
	}
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		++str;
	}
	return (number);
}
