/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:40:03 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/02 19:54:17 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	render(t_game *game)
{
	load_assets(game, TILE_S, TILE_S);
	render_map(game);
	render_player(game);
}

void	render_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->txtrs.player, x * TILE_S, y * TILE_S);
				game->player.x = x;
				game->player.y = y;
			}
			x++;
		}
		y++;
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			render_map_handler(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_score_handler(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'U')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->txtrs.score[0], x * TILE_S, y * TILE_S);
	else if (game->map.map[y][x] == 'D')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->txtrs.score[0], x * TILE_S, y * TILE_S);
	else if (game->map.map[y][x] == 'H')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->txtrs.score[0], x * TILE_S, y * TILE_S);
}

void	render_map_handler(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.ground, x
		* TILE_S, y * TILE_S);
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.wall,
			x * TILE_S, y * TILE_S);
	else if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->txtrs.gather, x * TILE_S, y * TILE_S);
	else if (game->map.map[y][x] == 'V')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->txtrs.ennemy[0], x * TILE_S, y * TILE_S);
	else if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->txtrs.exit_closed, x * TILE_S, y * TILE_S);
	render_score_handler(game, x, y);
}
