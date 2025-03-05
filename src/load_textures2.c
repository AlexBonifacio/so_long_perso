/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:37:20 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/05 15:22:27 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	load_exit_closed(t_game *game, int w, int h)
{
	w = game->exit.x;
	h = game->exit.y;
	game->txtrs.exit_closed = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/extracted_nature/tile_2_7.xpm", &w, &h);
	if (!game->txtrs.exit_closed)
	{
		w_error("Error : fail to load exit\n");
		free_game(game);
		exit(1);
	}
}

void	load_exit(t_game *game, int w, int h)
{
	w = game->exit.x;
	h = game->exit.y;
	game->txtrs.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/extracted_floor/tile_10_12.xpm", &w, &h);
	if (!game->txtrs.exit)
	{
		w_error("Error : fail to load exit\n");
		free_game(game);
		exit(1);
	}
}
