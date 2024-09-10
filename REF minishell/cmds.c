/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:16:00 by negambar          #+#    #+#             */
/*   Updated: 2024/09/10 15:22:36 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_home(t_env *environment)
{
	int		i;
	char	*home;

	i = 0;
	while (environment->reference[i])
	{
		if (ft_strncmp(environment->reference[i], "HOME=", 5) == 0)
			break ;
		i++;
	}
	home = ft_substr((const char *)environment->reference[i], 5, \
		(ft_strlen(environment->reference[i])));
	printf("PWD:: %s\n", home);
	return (home);
}

static void print_env(t_env *envi)
{
	int i;

	i = 0;
	while (envi->reference[i])
	{
		printf("%s\n", envi->reference[i]);
		i++;
	}	
}

void	use_cmds(t_shell *shell, t_env *environment)
{
	int		i;
	char	buff[1000];
	char	*c;

	i = 0;
	while (shell->mtx[i])
		i++;
	if (ft_strcmp(shell->mtx[0], "cd") == 0 && i == 1)
		chdir((const char *)find_home(environment));
	else if (ft_strcmp(shell->mtx[0], "env") == 0 && i == 1)
		print_env(environment);
	c = getcwd(buff, sizeof(buff));
}
