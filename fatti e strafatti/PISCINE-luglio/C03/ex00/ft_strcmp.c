/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:58:09 by negambar          #+#    #+#             */
/*   Updated: 2023/09/09 14:58:12 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int
	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*int	main(void)
{
	char *s1;
	char *s2;

	s1 = "aAa";
	s2 = "aaa";

	int result;
	result = ft_strcmp(s1, s2);
	printf("%i", result);

}*/
