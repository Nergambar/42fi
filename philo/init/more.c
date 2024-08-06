/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:59:23 by negambar          #+#    #+#             */
/*   Updated: 2024/07/23 14:08:32 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	more_forks(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->n_phi)
		pthread_mutex_init(&p->forks[i], NULL);
	i = -1;
	while (++i < p->n_phi)
	{
		p[i].leftf = &p->forks[i];
		if (i == p->n_phi - 1)
			p[i].rightf = &p->forks[0];
		else
			p[i].rightf = &p->forks[i + 1];
	}
}

static void	more_phil(t_philo *p, char **av)
{
	int	i;

	i = -1;
	while (++i < p->n_phi)
	{
		p[i].n_phi = ft_atoi(av[1]);
		p[i].id = i + 1;
		p[i].one = p[0].one;
		p[i].check = 0;
		p[i].each_eat = 0;
		pthread_mutex_init(&p[i].lock, NULL);
	}
}

static void	stayin_alive(t_philo *p, int ac, char **av)
{
	p->n_phi = ft_atoi(av[1]);
	p->one = malloc(sizeof(struct s_vitals));
	if (!p->one)
	{
		free(p);
		return (final_exit(&p));
	}
	if (ac == 6)
		p->one->full = ft_atoi(av[5]);
	else
		p->one->full = -1;
	p->one->start_engines = p_time();
	p->one->sleepy_time = ft_atoi(av[4]);
	p->one->t_death = ft_atoi(av[2]);
	p->one->t_eat = ft_atoi(av[3]);
	p->one->exit = 0;
	p->one->end = 0;
	pthread_mutex_init(&p->one->l_eat, NULL);
	pthread_mutex_init(&p->one->l_enddie, NULL);
	pthread_mutex_init(&p->one->message, NULL);
}

void	start_this_all(int ac, char **av, t_philo *p)
{
	stayin_alive(p, ac, av);
	p->t_id = malloc(sizeof(pthread_t *) * p->n_phi);
	p->forks = malloc(sizeof(pthread_mutex_t) * p->n_phi);
	if (!p->forks || !p->t_id || !p)
		return (final_exit(&p));
	pthread_mutex_init(&p->lock, NULL);
	more_forks(p);
	more_phil(p, av);
}
