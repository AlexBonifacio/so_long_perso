/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:25:45 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/06 19:45:15 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	load_assets(t_game *game, int w, int h)
{
	load_walls(game, w, h);
	load_ground(game, w, h);
	load_player(game, w, h);
	load_gather(game, w, h);
	load_exit(game, w, h);
	load_exit_closed(game, w, h);
	load_digits(game);
	load_ennemy(game, w, h);
}

void	load_walls(t_game *game, int w, int h)
{
	game->txtrs.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/extracted_nature/tile_1_7.xpm", &w, &h);
	if (!game->txtrs.wall)
	{
		w_error("Error: fail to load walls\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void	load_ground(t_game *game, int w, int h)
{
	game->txtrs.ground = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/extracted_textures/tile_8_4.xpm", &w, &h);
	if (!game->txtrs.ground)
	{
		w_error("Error: fail to load ground\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void	load_player(t_game *game, int w, int h)
{
	game->txtrs.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/extracted_char/tile_1_4.xpm", &w, &h);
	if (!game->txtrs.player)
	{
		w_error("Error: fail to load player\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void	load_gather(t_game *game, int w, int h)
{
	game->txtrs.gather = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/extracted_textures/tile_10_8.xpm", &w, &h);
	if (!game->txtrs.gather)
	{
		w_error("Error: fail to load gather\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}
