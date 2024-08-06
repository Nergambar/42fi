/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:33:02 by negambar          #+#    #+#             */
/*   Updated: 2024/08/06 11:57:46 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	checking(t_philo *p, long long t, int i)
{
	pthread_mutex_lock(&p->lock);
	pthread_mutex_lock(&p->one->message);
	if (p->check == 0)
	{
		if ((t - p[i].start_the_clock) > p->one->t_death)
		{
			pthread_mutex_unlock(&p->one->message);
			pthread_mutex_unlock(&p->lock);
			p_stats("\033[1;30mis dying\033[m", p);
			pthread_mutex_lock(&p->one->message);
			p->one->exit = 1;
			pthread_mutex_unlock(&p->one->message);
			return (1);
		}
	}
	pthread_mutex_unlock(&p->one->message);
	pthread_mutex_unlock(&p->lock);
	return (0);
}

static void	continuing_death(t_philo *p)
{
	int			i;
	long long	t;

	i = 0;
	while (i < p->n_phi)
	{
		t = p_time();
		if (checking(p, t, i))
			break ;
		i++;
	}
}

void	*time_deathh(t_philo *p)
{
	while (1 == 1)
	{
		pthread_mutex_lock(&p->one->message);
		if (p->one->exit)
		{
			pthread_mutex_unlock(&p->one->message);
			break ;
		}
		if (p->one->end == p->n_phi)
		{
			p->one->exit = 1;
			pthread_mutex_unlock(&p->one->message);
			break ;
		}
		pthread_mutex_unlock(&p->one->message);
		continuing_death(p);
	}
	return (0);
}
