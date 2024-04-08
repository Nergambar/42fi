/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:38:53 by negambar          #+#    #+#             */
/*   Updated: 2024/04/08 13:02:34 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 20
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./printf/ft_printf.h"
# include <stdio.h>
# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WA "./textures/FG_Cellar-_1_.xpm"
# define VO	"./textures/FG_Cellar .xpm"
# define PL "./textures/player.xpm"
# define CO "./textures/MonedaR.xpm"
# define EX "./textures/FG_Cellar-_2_.xpm"
# define MAP 32

typedef struct s_struct
{
	char	**matrix;
	void	*play;
	void	*wall;
	void	*coll;
	void	*vsp;
	void	*exit;
	void	*mlx;
	void	*wi;
	int		*xy;
	int		moves;
	int		pos[2];
	int		pcount;
	int		ecount;
	int		collcount;
	int		flag;
}	t_struct;

void	init_graphics(t_struct *sprites, int x, int y);
void	events(t_struct *loop);
void	all_together(t_struct *loop, int x, int y);
int		map_free(char **mtx, t_struct *loop);

char	*get_next_line(int fd);
int		ft_close(t_struct **loop);
int		close_wind(int key, t_struct *loop);
void	floodfill(char **mtx, int y, int x);
size_t	ft_strlen(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, char stop_char);
char	*ft_calloc(size_t count, size_t size);

void	image(t_struct *sprites);
void	checker(t_struct *sprites, int i, int j);
int		twindow(t_struct *sprites);

int		check_quantity(char **mtx, t_struct *sprites);
int		checkfill(char **mtx);
void	check_for_player(t_struct *sprites);
int		checkmap(t_struct *loop, char **mtx, int i, int j);
int		error_check(char **mtx);
int		is_walled(char **mtx);
int		is_walled2(char **mtx);
int		wall_maria(char **mtx);
int		valid_map(char **av);

void	mtx(char **av, t_struct *sprites);
int		get_l(char **matrix);
int		get_h(char **matrix);
int		valid_map(char **av);
char	**mtxdup(char **mtx);
void	clearmtx(char **matrix);

void	printmv(int moves);
void	check_for_player(t_struct *sp);
void	up(t_struct *sp);
void	down(t_struct *sp);
void	left(t_struct *sp);
void	right(t_struct *sp);
#endif
