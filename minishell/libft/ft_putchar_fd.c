/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:06:21 by negambar          #+#    #+#             */
/*   Updated: 2024/09/02 12:44:52 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd)
		write(fd, &c, 1);
}
/*
int main(int ac, char **av)
{
	ft_putchar_fd('c', 1);
}*/
