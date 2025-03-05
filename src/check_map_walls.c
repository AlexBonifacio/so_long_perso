/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:52:48 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/05 11:48:18 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_walls_error(t_game *game)
{
	w_error("Error: map is not closed\n");
	free_map(game);
	exit(EXIT_FAILURE);
}

void	map_walls_horiz(t_game *game)
{
	int	height;
	int	y;

	height = game->map.height_tiles - 1;
	y = 0;
	while (game->map.map[0][y])
	{
		if (game->map.map[0][y] != '1')
			map_walls_error(game);
		y++;
	}
	y = 0;
	while (game->map.map[height][y])
	{
		if (game->map.map[height][y] != '1')
			map_walls_error(game);
		y++;
	}
}

void	map_walls_vert(t_game *game)
{
	int	width;
	int	x;

	width = game->map.width_tiles - 1;
	x = 0;
	while (game->map.map[x] && x < game->map.height_tiles)
	{
		if (game->map.map[x][0] != '1')
			map_walls_error(game);
		x++;
	}
	x = 0;
	while (game->map.map[x] && x < game->map.height_tiles)
	{
		if (game->map.map[x][width] != '1')
			map_walls_error(game);
		x++;
	}
}

void	check_map_walls(t_game *game)
{
	map_walls_horiz(game);
	map_walls_vert(game);
}
