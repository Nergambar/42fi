/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:05:22 by negambar          #+#    #+#             */
/*   Updated: 2024/07/24 13:40:27 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	phil(t_philo *p)
{
	p->forks = malloc(sizeof(pthread_mutex_t));
	p->t_id = malloc(sizeof(pthread_t *));
	if (!p->forks || !p->t_id)
		return (final_exit(&p));
	pthread_mutex_init(&p->forks[0], NULL);
	p[0].leftf = &p->forks[0];
	p[0].id = 1;
}

static void	alive(t_philo *p, char **av, int ac)
{
	p->one = malloc(sizeof(struct s_vitals));
	p->one->start_engines = p_time();
	p->one->t_death = ft_atoi(av[2]);
	p->one->t_eat = ft_atoi(av[3]);
	p->one->exit = 0;
	p->one->sleepy_time = ft_atoi(av[5]);
	if (ac == 6)
		p->one->full = ft_atoi(av[5]);
	else
		p->one->full = -1;
}

void	start_alive(char **av, int ac, t_philo *p)
{
	alive(p, av, ac);
	p->n_phi = 1;
	pthread_mutex_init(&p->lock, NULL);
	return (phil(p));
}
