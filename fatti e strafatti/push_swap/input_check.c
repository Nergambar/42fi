/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:26:59 by negambar          #+#    #+#             */
/*   Updated: 2024/07/16 16:42:21 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '-' || av[i] == '-') && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '-' || av[i] == '+'))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

static int	valcount_zeros(char **b)
{
	int	i;
	int	nb_zeros;

	i = 0;
	nb_zeros = 0;
	while (b[++i])
	{
		if (!arg_is_number(b[i]))
			return (0);
		nb_zeros += arg_is_zero(b[i]);
	}
	return (nb_zeros);
}

int	correct(char **av, int ac)
{
	char	**b;
	int		nb_zeros;

	b = NULL;
	if (ac == 2)
		b = ft_split(av[1], ' ');
	if (!av || !av[1])
		return (free_mtx(b), 0);
	else
	{
		free_mtx(b);
		b = mtx_dup(&av[1]);
		if (!b)
			return (0);
	}
	nb_zeros = valcount_zeros(b);
	if (nb_zeros > 1)
	{
		free_mtx(b);
		exit_error(1);
		return (0);
	}
	free_mtx(b);
	return (1);
}
