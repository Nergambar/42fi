/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:16:00 by negambar          #+#    #+#             */
/*   Updated: 2024/09/09 14:27:25 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *find_home(t_env *environment)
{
	int i;
	int j;
	char *home;

	while (ft_strcmp(environment->reference, "HOME=") != 0)
	{
		environment = environment->next;
	}
	i = 5;
	while (environment->reference[j])
		j++;
	home = (char *)malloc(sizeof(char) * (j+1));
	j = 0;
	while (i < j)
	{
		home[j++] = environment->reference[i++];
	}
	home[j] = '\0';
	printf("HOME:::::%s\n", home);
	return (home);
}

void use_cmds(t_shell *shell)
{
	int i;
	char *buff[1000];

	i = 0;
	while (shell->mtx[i])
		i++;
	if (ft_strcmp(shell->mtx[0], "cd") == 0 && i == 1)
		chdir("~");
	char *c = getcwd(buff, sizeof(buff));
	printf("pwd: %s\n", c);
	
}