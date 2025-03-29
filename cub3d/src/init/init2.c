/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:16:25 by negambar          #+#    #+#             */
/*   Updated: 2025/03/28 14:22:42 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	dup_texture(t_game *game, char *texture, char *dir, int skip)
{
	if (!ft_strcmp(dir, "NO"))
		game->map_data.tex_no = ft_strdup(&texture[2 + skip]);
	else if (!ft_strcmp(dir, "SO"))
		game->map_data.tex_so = ft_strdup(&texture[2 + skip]);
	else if (!ft_strcmp(dir, "WE"))
		game->map_data.tex_we = ft_strdup(&texture[2 + skip]);
	if (!ft_strcmp(dir, "EA"))
		game->map_data.tex_ea = ft_strdup(&texture[2 + skip]);
}

void	txt_path(t_game *game, t_map *map)
{
	int		i;
	int		j;
	int		skip;
	char	**texture;

	skip = 0;
	j = 0;
	i = 0;
	texture = map->texture;
	while (texture[i] && j <= 5)
	{
		skip = skip_spaces(&texture[i][2]);
		if (!ft_strncmp(texture[i], "NO", 2))
			dup_texture(game, texture[i], "NO", skip);
		else if (!ft_strncmp(texture[i], "SO", 2))
			dup_texture(game, texture[i], "SO", skip);
		else if (!ft_strncmp(texture[i], "WE", 2))
			dup_texture(game, texture[i], "WE", skip);
		else if (!ft_strncmp(texture[i], "EA", 2))
			dup_texture(game, texture[i], "EA", skip);
		j++;
		i++;
	}
}
/*
 * The mlx_get_data_addr function returns information about a created image, allowing a user to modify it later.
 It takes the image to use, and the number of bits needed to represent a pixel color (bits_per_pixel). 
 mlx_get_data_addr returns an address that represents the beginning of the memory where the image is stored
*/
static int	data_address(t_game *game)
{
	void	*tmp_no;
	void	*tmp_so;
	void	*tmp_we;
	void	*tmp_ea;
	int		*tmp_endian;

	tmp_no = game->tx_n.img.mlx_img;
	tmp_so = game->tx_s.img.mlx_img;
	tmp_we = game->tx_w.img.mlx_img;
	tmp_ea = game->tx_e.img.mlx_img;
	tmp_endian = &game->tx_n.img.endian;
	if (!tmp_no || !tmp_so || !tmp_we || !tmp_ea || !tmp_endian)
		return (0);
	game->tx_n.img.addr = mlx_get_data_addr(tmp_no,
			&game->tx_n.img.bpp,
			&game->tx_n.img.line_len, tmp_endian);
	game->tx_s.img.addr = mlx_get_data_addr(tmp_so,
			&game->tx_s.img.bpp,
			&game->tx_s.img.line_len, tmp_endian);
	game->tx_w.img.addr = mlx_get_data_addr(tmp_we,
			&game->tx_w.img.bpp,
			&game->tx_w.img.line_len, tmp_endian);
	game->tx_e.img.addr = mlx_get_data_addr(tmp_ea, &game->tx_e.img.bpp,
			&game->tx_e.img.line_len, tmp_endian);
	return (1);
}

static void	file_to_image(t_game *game)
{
	char	*tmp_no;
	char	*tmp_so;
	char	*tmp_we;
	char	*tmp_ea;

	tmp_no = ft_strdup(game->map_data.tex_no);
	tmp_so = ft_strdup(game->map_data.tex_so);
	tmp_we = ft_strdup(game->map_data.tex_we);
	tmp_ea = ft_strdup(game->map_data.tex_ea);
	game->tx_n.img.mlx_img = mlx_xpm_file_to_image(game->mlx, tmp_no,
			&game->tx_n.img.width, &game->tx_n.img.height);
	game->tx_s.img.mlx_img = mlx_xpm_file_to_image(game->mlx, tmp_so,
			&game->tx_s.img.width, &game->tx_s.img.height);
	game->tx_w.img.mlx_img = mlx_xpm_file_to_image(game->mlx, tmp_we,
			&game->tx_w.img.width, &game->tx_w.img.height);
	game->tx_e.img.mlx_img = mlx_xpm_file_to_image(game->mlx, tmp_ea,
			&game->tx_e.img.width, &game->tx_e.img.height);
	free(tmp_no);
	free(tmp_so);
	free(tmp_we);
	free(tmp_ea);
}

void	create_textures(t_game *game, t_map *map)
{
	txt_path(game, map);
	init_struct(game);
	file_to_image(game);
	data_address(game);
	if (!data_address(game) || !game->tx_n.img.mlx_img
		|| !game->tx_s.img.mlx_img
		|| !game->tx_w.img.mlx_img || !game->tx_e.img.mlx_img)
	{
		printf("Path to textures does not exist or cannot be accessed\n");
		free_matrix(game->map);
		free_map(map);
		free_textures(game);
		destroy_image(game);
		free(game->img.mlx_img);
		exit(1);
	}
}
