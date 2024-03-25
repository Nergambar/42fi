/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:10:24 by negambar          #+#    #+#             */
/*   Updated: 2024/03/04 12:53:14 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"

void	ft_handler(int signal)
{
	static int	bit = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		bit |= (0x01 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", bit);
		bit = 0;
		i = 0;
	}
}

/* 	(void)av; fa evitare i warnings del compiler */
int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sig;

	(void)av;
	if (ac > 1)
	{
		ft_printf("\033[91mWRONG NUMBERS OF ARGUMENTS.\033[0m\n");
		ft_printf("\033[33m./server\033[0m\n");
		return (1);
	}
	else
	{
		pid = getpid();
		sig = (struct sigaction){0};
		sig.sa_handler = ft_handler;
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
		ft_printf("\033[90mWaiting... \033[0m\n");
		while (1)
			pause();
	}
	return (0);
}
