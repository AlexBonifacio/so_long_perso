/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:19:22 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/02 20:23:04 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	update_map(t_game *game, int old_x, int old_y)
{
	game->map.map[old_y][old_x] = '0';
	game->map.map[game->player.y][game->player.x] = 'P';
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.ground,
		old_x * TILE_S, old_y * TILE_S);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.player,
		game->player.x * TILE_S, game->player.y * TILE_S);
}

int	main(void)
{
	t_game	game;

	init_structs_null(&game);
	game.map.map = load_map("map.ber");
	map_checker(&game);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		free_game(&game);
	get_map_size(&game, &game.map.width, &game.map.height);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map.width,
			game.map.height, "so_long");
	if (!game.win_ptr)
		free_game(&game);
	render(&game);
	game.map.coins = count_in_map(&game, 'C');
	mlx_loop_hook(game.mlx_ptr, animate_enemies, &game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, key_handler, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
}
