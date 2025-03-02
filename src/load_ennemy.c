/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ennemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:41:39 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/01 23:09:55 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	load_ennemy(t_game *game, int w, int h)
{
	game->txtrs.ennemy[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/extracted_ennemy/tile_1_1.xpm", &w, &h);
	game->txtrs.ennemy[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/extracted_ennemy/tile_2_1.xpm", &w, &h);
	game->txtrs.ennemy[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/extracted_ennemy/tile_3_1.xpm", &w, &h);
	game->txtrs.ennemy[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/extracted_ennemy/tile_4_1.xpm", &w, &h);
	if (!game->txtrs.ennemy[0] || !game->txtrs.ennemy[1]
		|| !game->txtrs.ennemy[2] || !game->txtrs.ennemy[3])
	{
		w_error("Error: fail to load ennemy\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}



