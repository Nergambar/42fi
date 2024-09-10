/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:06:01 by negambar          #+#    #+#             */
/*   Updated: 2024/09/10 10:58:31 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/mman.h>
# include "libft/libft.h"

typedef struct s_env
{
	char			**reference;
	struct s_env	*next;
}		t_env;

typedef struct s_shell
{
	char	**mtx;
	char	*new;
	t_env	*env;
	int		res;
	int		*fd;
}				t_shell;

void	use_cmds(t_shell *shell, t_env *environment);

#endif