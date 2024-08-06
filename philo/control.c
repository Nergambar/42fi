/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:01:45 by negambar          #+#    #+#             */
/*   Updated: 2024/08/06 11:57:46 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	route(t_philo *p)
{
	p_stats("\e[1;34mis sleeping\e[m", p);
	waiting(p->one->sleepy_time);
	p_stats("\033[1;31mis thinking\033[m", p);
}

static int	all_eat(t_philo *p)
{
	if (p->each_eat == p->one->full)
	{
		pthread_mutex_lock(&p->one->message);
		p->one->end = p->one->end + 1;
		pthread_mutex_unlock(&p->one->message);
		pthread_mutex_lock(&p->lock);
		p->check = 1;
		pthread_mutex_unlock(&p->lock);
		pthread_mutex_lock(&p->one->message);
		if (p->one->end == p->n_phi)
		{
			p->one->exit = 1;
			pthread_mutex_unlock(&p->one->message);
			return (1);
		}
		pthread_mutex_unlock(&p->one->message);
		return (1);
	}
	return (0);
}

static void	*life(void *philos)
{
	t_philo	*p;

	p = philos;
	if (p->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&p->one->message);
		if (p->one->exit == 1)
		{
			pthread_mutex_unlock(&p->one->message);
			break ;
		}
		pthread_mutex_unlock(&p->one->message);
		if (all_eat(p) == 1)
			break ;
		eating(p);
		if (all_eat(p) == 1)
			break ;
		route(p);
	}
	return (0);
}

void	more(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->n_phi)
	{
		p[i].start_the_clock = p_time();
		pthread_create(&p->t_id[i], NULL, life, (void *)&p[i]);
	}
	time_deathh(p);
	i = -1;
	while (++i < p->n_phi)
		pthread_join(p->t_id[i], NULL);
	final_exit(&p);
}
