/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:19:22 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/07 19:51:05 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		free_game(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.width,
			game->map.height, "so_long");
	if (!game->win_ptr)
		free_game(game);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	check_arg(argc, argv);
	init_structs_null(&game);
	game.map.map = load_map(argv[1]);
	map_checker(&game);
	init_mlx(&game);
	render(&game);
	game.dynamic_sleep_time = init_dynamic_sleep();
	mlx_loop_hook(game.mlx_ptr, game_loop, &game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, key_handler, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
}
