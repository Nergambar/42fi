/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:47:06 by negambar          #+#    #+#             */
/*   Updated: 2023/09/07 18:47:15 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int
	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] > 31 && str[i] < 127)))
			return (0);
		i++;
	}
	return (1);
}

/*int main(void)
{
    char *str = "aaaaaa\naaaaaaaaa1aaaaa";
    int result = ft_str_is_printable(str);
    
    printf("%i", result);
    
    return 0;
}*/
