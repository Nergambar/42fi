/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:42:48 by negambar          #+#    #+#             */
/*   Updated: 2024/05/06 12:47:58 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

#  include "../push_swap.h"

int		ft_isalpha(int c);
int		ft_isascii(int c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, char *c);
char	*ft_strrchr(const char *s, int c);\
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_bzero(void *s, int n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);

#endif
