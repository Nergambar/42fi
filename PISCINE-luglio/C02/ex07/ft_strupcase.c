/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:55:55 by negambar          #+#    #+#             */
/*   Updated: 2023/09/07 18:56:00 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char
	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (str);
}

/*int main(void)
{
    char str[] = "aaaaaaaaaaaaaaaaaa";
    char *result = ft_strupcase(str);
    
    printf("%s", result);
}*/
