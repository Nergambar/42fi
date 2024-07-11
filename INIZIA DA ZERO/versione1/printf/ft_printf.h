/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:48:50 by negambar          #+#    #+#             */
/*   Updated: 2024/05/03 13:21:29 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		ft_print_c(int c);
int		ft_print_perc(void);
int		ft_print_n(int n);
int		ft_print_u(unsigned int i);
int		ft_print_s(char *str);
int		ft_print_hex(unsigned long num, const char format);
int		ft_print_ptr(unsigned long long ptr);
#endif