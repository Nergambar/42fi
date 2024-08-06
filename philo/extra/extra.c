/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:08:16 by negambar          #+#    #+#             */
/*   Updated: 2024/07/22 12:52:15 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	p_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	helper(t_philo **p)
{
	if ((*p)->forks)
	{
		free((*p)->forks);
		(*p)->forks = NULL;
	}
	if ((*p)->t_id)
	{
		free((*p)->t_id);
		(*p)->t_id = NULL;
	}
}

void	final_exit(t_philo **p)
{
	int	i;

	if (*p == NULL || (*p)->forks == 0)
		return ;
	if ((*p)->n_phi != 0)
	{
		i = -1;
		while (++i < (*p)->n_phi)
		{
			pthread_mutex_destroy(&(*p)->forks[i]);
			pthread_mutex_destroy(&(*p)[i].lock);
		}
		if ((*p)->n_phi >= 2)
		{
			pthread_mutex_destroy(&(*p)->one->l_enddie);
			pthread_mutex_destroy(&(*p)->one->l_eat);
			pthread_mutex_destroy(&(*p)->one->message);
		}
	}
	helper(p);
}
