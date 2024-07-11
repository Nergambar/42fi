/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:30:13 by negambar          #+#    #+#             */
/*   Updated: 2024/05/28 12:19:42 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoimdf(const char *nptr)
{
	int		i;
	int		sign;
	int		result;
	char	*str;

	str = (char *)nptr;
	if (!check_number(str))
		fterror(2);
	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += str[i] - '0';
		}
		else
			fterror(2);
		i++;
	}
	return (sign * result);
}

