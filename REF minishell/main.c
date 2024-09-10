/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:51:25 by negambar          #+#    #+#             */
/*   Updated: 2024/09/10 16:53:03 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

char	**set_prompt(char *str)
{
	char	**mtx;

	mtx = NULL;
	mtx = ft_split(str, ' ');
	if (!mtx)
		return (NULL);
	return (mtx);
}

// void	free_the_shell(t_shell *shell)
// {
// 	int	i;

// 	if (shell)
// 	{
// 		i = 0;
// 		if (shell->new)
// 			free(shell->new);
// 		if (shell->mtx)
// 		{
// 			while (shell->mtx[i++])
// 				free(shell->mtx[i]);
// 			free(shell->mtx);
// 		}
// 		if (shell->fd)
// 			free(shell->fd);
// 	}
// 	free(shell);
// }

t_env	*new_environment(char **env)
{
	t_env	*enviroment;
	int		i;

	i = 0;
	enviroment = ft_calloc(1, sizeof(t_env));
	while (env[i])
		i++;
	enviroment->reference = (char **)malloc(sizeof(char *) * (i + 1));
	if (!enviroment->reference)
		return (NULL);
	i = 0;
	while (env[i] != NULL)
	{
		enviroment->reference[i] = ft_strdup(env[i]);
		i++;
	}
	enviroment->reference[i] = NULL;
	return (enviroment);
}

// static int checkexit(t_shell *shell)
// {
// 	if ((ft_strcmp(shell->mtx[0], "exit") == 0 && !(shell->mtx[1])) || \
// 		(ft_strcmp(shell->mtx[0], "quit") == 0 && !(shell->mtx[1])) || \
// 		(ft_strcmp(shell->mtx[0], "q") == 0 && !(shell->mtx[1])))
// 		return(0);
// 	return (1);
// }

int	main(int ac, char **av, char **enviroment)
{
	char	*str;
	t_shell	*main_shell;
	//dicharazione struct shell
	main_shell = (t_shell *)malloc(sizeof(t_shell));
	if (!main_shell)
		return (exit_failure)//FIND LIBRARY
	main_shell->env = new_environment(enviroment);
	//leggi ed esegui se possibile 
	if (ac == 1)
	{
		while (1)
		{
			str = readline("prompt: ");
			main_shell->mtx = set_prompt(str);
			if (!main_shell)
			{
			/* da rivedere */
				free(str);
				break ;
				//exit
			}
			free(str); 
			use_cmds(main_shell, enviroment);
			add_history(str);
			free(str);
			if (!checkexit(main_shell))
			{
				free_the_shell(main_shell);
				clear_history();
				break ;
			}
			printf("str %s\n", str);
			free_the_shell(main_shell);
		}
	}
	int i = 0;
	while (enviroment->reference[i])
	{
		free(enviroment->reference[i]);
		i++;
	}
	free(enviroment->reference);
	free((void*)enviroment);
	clear_history();
	return (0);
}
