/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:15:23 by negambar          #+#    #+#             */
/*   Updated: 2023/09/09 15:15:25 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int
	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;

	while ((s1[i] && s2[i]) || i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return(0);
}


int	main(void)
{
	char *s1;
	char *s2;
	unsigned int n;

	s1 = "Prova";
	s2 = "Prov";
	n = 5;

	int result1 = ft_strncmp(s1, s2, n); // Compare the first 5 characters
    printf("Comparison result (first 5 characters): %d\n", result1);
}
