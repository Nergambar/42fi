/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:16:25 by negambar          #+#    #+#             */
/*   Updated: 2024/08/06 11:57:46 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	invalid_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac != 5 && ac != 6)
		return (ft_error("Error: not enough!\n"), 0);
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
		return (ft_error("Error:Hey now, hey now..the philosophers!\n"), 0);
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return (ft_error("Error: invalid time!\n"), 0);
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] < '0' && av[j][i] > '9')
				return (ft_error("Error: check the input!\n"), 0);
			i++;
		}
		j++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo	*p;

	if (!invalid_args(ac, av))
		return (0);
	if (ft_atoi(av[1]) == 1)
	{
		printf("\033[1;32m0 1 has taken a fork\033[m\n");
		usleep(ft_atoi(av[2]));
		printf("\033[1;30m%d 1 has died\033[m\n", ft_atoi(av[2]));
		return (0);
	}
	p = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (ft_atoi(av[1]) > 1)
	{
		start_this_all(ac, av, p);
		more(p);
	}
	free((p->one));
	final_exit(&p);
	if (!p)
		free(p);
	free(p);
}
