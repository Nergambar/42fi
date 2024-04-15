/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:32:54 by negambar          #+#    #+#             */
/*   Updated: 2023/09/07 18:32:56 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int
	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return(0);
		i++;
	}
	return (1);
}

/*int main(void)
{
    char *str = "11111 111";
    int result = ft_str_is_numeric(str);
    
    printf("%i", result);
    
    return 0;
}*/
