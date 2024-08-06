/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:07:44 by negambar          #+#    #+#             */
/*   Updated: 2024/08/06 11:57:46 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	p_stats(char *s, t_philo *p)
{
	pthread_mutex_lock(&p->one->message);
	if (!p->one->exit)
	{
		pthread_mutex_unlock(&p->one->message);
		pthread_mutex_lock(&p->one->message);
		printf("\033[1;35m%lld\033[m \033[1;36m%d\033[m %s\n", p_time() - p->one->start_engines, p->id, s);
		pthread_mutex_unlock(&p->one->message);
		return ;
	}
	pthread_mutex_unlock(&p->one->message);
}

static void	take_fork_drop(t_philo *p)
{
	if (p->id == p->n_phi)
	{
		pthread_mutex_lock(p->leftf);
		p_stats("\033[1;32mhas taken a fork\033[m", p);
		pthread_mutex_lock(p->rightf);
		p_stats("\033[1;32mhas taken a fork\033[m", p);
	}
	else
	{
		pthread_mutex_lock(p->rightf);
		p_stats("\033[1;32mhas taken a fork\033[m", p);
		pthread_mutex_lock(p->leftf);
		p_stats("\033[1;32mhas taken a fork\033[m", p);
	}
}

static void	dropping(t_philo *p)
{
	if (p->id == p->n_phi)
	{
		pthread_mutex_unlock(p->leftf);
		pthread_mutex_unlock(p->rightf);
	}
	else
	{
		pthread_mutex_unlock(p->rightf);
		pthread_mutex_unlock(p->leftf);
	}
}

void	waiting(long long wait)
{
	long long	t;

	t = p_time() + wait;
	while (p_time() - t < 0)
		usleep(100);
}

void	eating(t_philo *p)
{
	take_fork_drop(p);
	pthread_mutex_lock(&p->lock);
	pthread_mutex_lock(&p->one->message);
	p->start_the_clock = p_time();
	pthread_mutex_unlock(&p->one->message);
	p->each_eat++;
	pthread_mutex_unlock(&p->lock);
	p_stats("is eating", p);
	waiting(p->one->t_eat);
	dropping(p);
}
