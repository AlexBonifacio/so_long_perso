/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:19:22 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/02 13:45:40 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	load_assets(t_game *game, int w, int h);

void	get_map_size(t_game *game, int *width, int *height)
{
	int	x;
	int	y;

	if ((!game->map.map) || (!game->map.map[0]))
	{
		w_error("Error: map is empty\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	
	y = 0;
	while (game->map.map[y])
		y++;
	*height = y * TILE_S;
	x = 0;
	while (game->map.map[0][x])
		x++;
	*width = x * TILE_S;
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
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.ennemy[0],
			x * TILE_S, y * TILE_S);
	else if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.exit_closed,
			x * TILE_S, y * TILE_S);
	render_score_handler(game, x, y);
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


void	update_map(t_game *game, int old_x, int old_y)
{
	game->map.map[old_y][old_x] = '0';
	game->map.map[game->player.y][game->player.x] = 'P';
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.ground,
		old_x * TILE_S, old_y * TILE_S);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.player,
		game->player.x * TILE_S, game->player.y * TILE_S);
}

int	check_move(t_game *game, char c)
{
	int x;
	int y;

	x = game->player.x;
	y = game->player.y;
	if (game->map.map[y][x + 1] != '1' && c == 'r')
		return (1);
	else if (game->map.map[y][x - 1] != '1' && c == 'l')
		return (1);
	else if (game->map.map[y - 1][x] != '1' && c == 'u')
		return (1);
	else if (game->map.map[y + 1][x] != '1' && c == 'd')
		return (1);
	return (0);
}

void	check_move_exit(t_game *game, int old_x, int old_y)
{
	if (game->player.game_won)
	{
		ft_printf("🎊 Congratulation ! You won ! 🎊\n");
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("🚫 You are missing coins! (%d/%d)\n", game->player.collected,
			game->map.coins);
		game->player.x = old_x;
		game->player.y = old_y;
	}
}



void	player_move(int key, t_game *game)
{
	static int	count;
	int			old_x;
	int			old_y;

	old_x = game->player.x;
	old_y = game->player.y;
	if (key == XK_Left && check_move(game, 'l'))
		game->player.x--;
	else if (key == XK_Right && check_move(game, 'r'))
		game->player.x++;
	else if (key == XK_Up && check_move(game, 'u'))
		game->player.y--;
	else if (key == XK_Down && check_move(game, 'd'))
		game->player.y++;
	if (game->map.map[game->player.y][game->player.x] == 'E')
		check_move_exit(game, old_x, old_y);
	count++;
	update_score(game, count);
	if (game->map.map[game->player.y][game->player.x] == 'C')
		game->player.collected++;
	ft_printf("Move count %i\n", count);
	update_map(game, old_x, old_y);
	if (game->player.collected == game->map.coins)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.exit,
			1 * TILE_S, 1 * TILE_S);
		game->player.game_won = 1;
	}
}




void	map_checker(t_game *game)
{
	if (!game->map.map)
	{
		w_error("Error: fail to load the map\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	check_nb_assets(game);
	find_score_position(game);
}


void	render(t_game *game)
{
	load_assets(game, TILE_S, TILE_S);
	render_map(game);
	render_player(game);
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
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map.width, game.map.height, "so_long");
	if (!game.win_ptr)
		free_game(&game);
	render(&game);
	game.map.coins = count_in_map(&game, 'C');
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, key_handler, &game);
	mlx_loop(game.mlx_ptr);
	mlx_destroy_display(game.mlx_ptr);
	free_game(&game);
}


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

void	display_tab(t_game game)
{
	int i = 0;
	int y = 0;
	while (game.map.map[i])
	{
		y = 0;
		while (game.map.map[i][y])
		{
			ft_printf("%c", game.map.map[i][y]);
			y++;
		}
		i++;
		ft_printf("\n");
	}
}