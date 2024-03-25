/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:38:53 by negambar          #+#    #+#             */
/*   Updated: 2024/03/23 15:51:39 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 100
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

#  define WALL "./xpm_files/FG_Cellar-_1_.xpm"
#  define VOID	"./xpm_files/FG_Cellar .xpm"
#  define PLAYER "./xpm_files/player.xpm"
#  define COLL "./xpm_files/MonedaR.xpm"
#  define EXIT "./xpm_files/FG_Cellar-_2_.xpm"
#  define SIZEMAP 32



typedef struct s_struct
{
	char **matrix;
	void *player;
	void *wall;
	void *coll;
	void *voidsp;
	void *exit;
	void *mlx;
	void *win;
	int *xy;
	int pos[2];
	//int ac;
	//char **av;
} t_struct;

char	*get_next_line(int fd);
void printmtx(char **mtx);
int ft_close(t_struct **loop);
int close_wind(int key, t_struct *loop);
int get_h(char **av);
int get_l(char **av);
void mtx(char **av, t_struct *sprites);
void clearmtx(char **matrix);
void checkfill(char **mtx, int y, int x);

void image(t_struct *sprites);
void checker(t_struct *sprites, int i, int j);
void twindow(t_struct *sprites);
char **mtxdup(char **mtx);


void check_for_player(t_struct *sprites);
void up(t_struct *sprites);
void down(t_struct *sprites);
void left(t_struct *sprites);
void right(t_struct *sprites);

#endif