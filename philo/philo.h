/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:47:29 by negambar          #+#    #+#             */
/*   Updated: 2024/07/23 12:45:30 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_t		*t_id;
	pthread_mutex_t	lock;
	pthread_mutex_t	*rightf;
	pthread_mutex_t	*leftf;
	pthread_mutex_t	*forks;
	int				n_phi;
	int				id;
	int				each_eat;
	int				check;
	long long		start_the_clock;
	struct s_vitals	*one;
}					t_philo;

typedef struct s_vitals
{
	pthread_mutex_t	l_eat;
	pthread_mutex_t	l_enddie;
	pthread_mutex_t	message;
	long long		start_engines;
	long long		t_eat;
	long long		sleepy_time;
	int				end;
	int				exit;
	int				t_death;
	int				full;
}					t_vitals;

/* utils */
int			ft_strlen(char *str);
int			ft_atoi(const char *nptr);
void		ft_error(char *str);
int			ft_strcmp(char *s1, char *s2);

/* extra */
long long	p_time(void);
void		helper(t_philo **p);
void		final_exit(t_philo **p);

/* init */
void		start_this_all(int ac, char **av, t_philo *p);
void		start_alive(char **av, int ac, t_philo *p);
void		waiting(long long wait);
void		eating(t_philo *p);
void		*time_deathh(t_philo *p);

void		more(t_philo *p);
void		p_stats(char *s, t_philo *p);

#endif