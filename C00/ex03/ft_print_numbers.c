/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:06:43 by negambar          #+#    #+#             */
/*   Updated: 2023/09/05 15:07:34 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	nb;

	nb = '0';
	while (nb <= '9')
	{
		write(1, &nb, 1);
		nb++;
	}
}
/*int	main(void)
{
	ft_print_numbers();
}*/
