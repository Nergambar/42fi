/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:26:07 by negambar          #+#    #+#             */
/*   Updated: 2023/09/09 16:26:09 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int len;
	int i;
	int j;

	len = 0;
	while (to_find[len])
	{
		len++;
	}
	if (len == 0)
		return (str);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (to_find[j] == str[i + j])
		{
			if (j + 1 == len)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}



int main(void)
{
    char str[] = "The cat is on the mat";
    char to_find[] = "cat";

    int result = ft_strstr(str, to_find);
    
    if (result == 1)
    {
        printf("The word \"%s\" was found in the sentence.\n", to_find);
    }
    else
    {
        printf("The word \"%s\" was not found in the sentence.\n", to_find);
    }

    return 0;
}
