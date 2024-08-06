/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:27:41 by negambar          #+#    #+#             */
/*   Updated: 2023/09/07 18:27:43 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>

int
	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')))
			return (0);
		i++;
	}
	return (1);
}
/*int main(void)
{
    char *str = "abcdefg1hijkl";
    int result = ft_str_is_alpha(str);

    printf("%i", result);

    return 0;
}
*/
