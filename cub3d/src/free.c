/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:31:31 by negambar          #+#    #+#             */
/*   Updated: 2025/03/10 11:55:10 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	free_colors(t_map *map)
{
	int	i;

	i = 0;
	if (map->f_alloc)
	{
		while (i != map->f_alloc)
		{
			free(map->f_color[i]);
			map->f_color[i] = NULL;
			i++;
		}
		free(map->f_color);
	}
	i = 0;
	if (map->c_alloc)
	{
		while (i != map->c_alloc)
		{
			free(map->c_color[i]);
			map->c_color[i] = NULL;
			i++;
		}
		free(map->c_color);
	}
}

void	free_map(t_map *map)
{
	free_matrix(map->map);
	free_matrix(map->texture);
	free_colors(map);
}

void	free_textures(t_game *game)
{
	if (game->map_data.tex_no)
		free(game->map_data.tex_no);
	if (game->map_data.tex_so)
		free(game->map_data.tex_so);
	if (game->map_data.tex_we)
		free(game->map_data.tex_we);
	if (game->map_data.tex_ea)
		free(game->map_data.tex_ea);
}

void	destroy_image(t_game *game)
{
	if (game->tx_n.img.mlx_img)
		mlx_destroy_image(game->mlx, game->tx_n.img.mlx_img);
	if (game->tx_s.img.mlx_img)
		mlx_destroy_image(game->mlx, game->tx_s.img.mlx_img);
	if (game->tx_e.img.mlx_img)
		mlx_destroy_image(game->mlx, game->tx_e.img.mlx_img);
	if (game->tx_w.img.mlx_img)
		mlx_destroy_image(game->mlx, game->tx_w.img.mlx_img);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
