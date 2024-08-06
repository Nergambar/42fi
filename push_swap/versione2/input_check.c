/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:51:09 by negambar          #+#    #+#             */
/*   Updated: 2024/07/10 13:30:16 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '-' || s[i] == '+') && s[i + 1] != '\0')
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i] != '\0' && !ft_isdigit(s[i]))
		return (0);
	return (1);
}

static int	dups(char *s)
{
	int	i;
	int j;

	i = 1;
	while (s[i])
	{
		j = 1;
		while (s[j])
		{
			if (j != i && nbstr_cmp(&s[i], &s[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_zero(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && s[i] == '0')
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}

int correct(char **av)
{
	int i;
	int nb_Z;

	nb_Z = 0;
	i = 1;
	while(av[i])
	{
		if (!is_num(av[i]))
			return (0);
		nb_Z += is_zero(av[i]);
		i++;
	}
	if (nb_Z > 1)
		return (0);
	if (dups(*av))
		return (0);
	return (1);
}