/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:51:25 by negambar          #+#    #+#             */
/*   Updated: 2024/09/09 16:19:16 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# include "libft/libft.h"

char	*new_string(char *str)
{
	int		i;
	char	s[2048];
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] <= 32)
		{
			while (str[i] <= 32 && str[i+1] <= 32)
				i++;
		}
		s[j++] = str[i];
		i++;
	}
	s[j] = '\0';
	return (ft_strdup(s));
}

t_shell	*set_structshell(char *str, t_env *enviroment)
{
	t_shell *shell;

	shell = ft_calloc(1, sizeof(t_shell));
	shell->new = new_string(str);
	shell->mtx = ft_split(shell->new, ' ');
	shell->env = enviroment;
	return(shell);
}

/* cerca home in env (strchr, salva in var, usa var per chdir), oldpwd != pwd. */

void	free_the_shell(t_shell *shell)
{
	int i;
	if (shell)
	{
		i = 0;
		if (shell->new)
			free(shell->new);
		if (shell->mtx)
		{
			while (shell->mtx[i++])
				free(shell->mtx[i]);
			free(shell->mtx);
		}
		if (shell->fd)
			free(shell->fd);
	}
	free(shell);
}


t_env *new_environment(char **env)
{
	t_env *enviroment;
	int i;

	i = 0;
	enviroment = ft_calloc(1, sizeof(t_env));
	while (env[i])
		i++;
	enviroment->reference = (char **)malloc(sizeof(char *) * (i + 1));
	if (!enviroment->reference)
		return(NULL);
	i = 0;
	while (env[i] != NULL)
	{
		enviroment->reference[i] = ft_strdup(env[i]);
		i++;
	}
	enviroment->reference[i] = NULL;
	return (enviroment);
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	char *str;
	t_shell	*main_shell;
	t_env *enviroment;


	enviroment = new_environment(env);
	str = NULL;
	if (ac == 1)
	{
		printf("(((_.-=-._.-=-._)))\n\
 ))~~~~~~~~~~~~~(( \n\
 (( >Minishell< ))\n\
 )).............(( \n\
(((`-._.-'`-._.-)))\n\n\n");
		while (1)
		{
			{
				str = readline("prompt: ");
				main_shell = set_structshell(str, NULL);
				use_cmds(main_shell, enviroment);
				add_history(str);
				free(str);
				printf("str %s\n", main_shell->new);
				free_the_shell(main_shell);
			}
		}
	}
	clear_history();
	return (0);
}