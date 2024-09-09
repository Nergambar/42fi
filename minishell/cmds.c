/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:16:00 by negambar          #+#    #+#             */
/*   Updated: 2024/09/09 16:35:43 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *find_home(t_env *environment)
{
	int i;
	char *home;

	i = 0;
	while (environment->reference[i])
	{
		if (ft_strncmp(environment->reference[i], "HOME=", 5) == 0)
			break;
		i++;
	}
	home = ft_substr((const char *)environment->reference[i], 5, (ft_strlen(environment->reference[i])));
	return (home);
}

void use_cmds(t_shell *shell, t_env *environment)
{
	int i;
	char buff[1000];

	i = 0;
	while (shell->mtx[i])
		i++;
	if (ft_strcmp(shell->mtx[0], "cd") == 0 && i == 1)
		chdir((const char *)find_home(environment));
	char *c = getcwd(buff, sizeof(buff));
	printf("pwd: %s\n", c);
}