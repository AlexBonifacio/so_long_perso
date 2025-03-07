/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:08:50 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/07 20:19:40 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <unistd.h>

int	animate_enemies(t_game *game)
{
	static int	frame_counter;
	static int	i;

	frame_counter++;
	if (i == ENNEMY_FRAMES)
		i = 0;
	if (frame_counter == FRAME_RATE)
	{
		frame_counter = 0;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->txtrs.ennemy[i], game->ennemy.x * TILE_S, game->ennemy.y
			* TILE_S);
		i++;
	}
	return (0);
}
