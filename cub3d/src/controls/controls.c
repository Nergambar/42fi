/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:16:48 by negambar          #+#    #+#             */
/*   Updated: 2025/03/29 09:54:58 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	handle_player_movement(t_game *game,
		float cos_angle, float sin_angle, int speed)
{
	t_player	*player;

	player = &game->player;
	if (player->key_up)
	{
		player->p_x += cos_angle * speed;
		player->p_y += sin_angle * speed;
	}
	if (player->key_down)
	{
		player->p_x -= cos_angle * speed;
		player->p_y -= sin_angle * speed;
	}
	if (player->key_left)
	{
		player->p_x += sin_angle * speed;
		player->p_y -= cos_angle * speed;
	}
	if (player->key_right)
	{
		player->p_x -= sin_angle * speed;
		player->p_y += cos_angle * speed;
	}
}
