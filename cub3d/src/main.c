/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:40:49 by negambar          #+#    #+#             */
/*   Updated: 2025/03/18 11:29:01 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	main(int ac, char **av)
{
	t_map		map;
	t_game		game;

	map = (t_map){0};
	game = (t_game){0};
	if (ac != 2)
		return (printf("Bad number of arguments!\n"));
	map_init(&map);
	if (map_parsing(av, &map))
		return (printf("Invalid map or configuration!\n"));
	if (game_init(av, &map, &game))
		return (printf("Error while initializing the game\n"));
	init_player(&game.player, &map);
	create_textures(&game, &map);
	game.map_ref = &map;
	mlx_hook(game.win, 17, 0, &exit_hook, &game);
	mlx_hook(game.win, 2, 1L << 0, &key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, &key_release, &game.player);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
