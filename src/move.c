/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:06:06 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/03 23:54:57 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

int	check_move(t_game *game, char c)
{
	int	x;
	int	y;

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
		ft_printf("🚫 You are missing coins! (%d/%d) 🚫\n",
			game->player.collected, game->map.coins);
		game->player.x = old_x;
		game->player.y = old_y;
	}
}

int	moves(int key, t_game *game)
{
	if (key == XK_Left && check_move(game, 'l'))
		return (game->player.x--);
	else if (key == XK_Right && check_move(game, 'r'))
		return (game->player.x++);
	else if (key == XK_Up && check_move(game, 'u'))
		return (game->player.y--);
	else if (key == XK_Down && check_move(game, 'd'))
		return (game->player.y++);
	return (0);
}

void	player_move(int key, t_game *game)
{
	static int	count;
	int			old_x;
	int			old_y;

	old_x = game->player.x;
	old_y = game->player.y;
	if (moves(key, game))
		count++;
	ft_printf("Move count %i\n", count);
	update_score(game, count);
	if (game->map.map[game->player.y][game->player.x] == 'E')
		check_move_exit(game, old_x, old_y);
	if (game->map.map[game->player.y][game->player.x] == 'V')
		ft_printf("💀 You died! 💀\n");
	if (game->map.map[game->player.y][game->player.x] == 'V')
		free_game(game);
	if (game->map.map[game->player.y][game->player.x] == 'C')
		game->player.collected++;
	update_map(game, old_x, old_y);
	if (game->player.collected == game->map.coins)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.exit,
			game->exit.x * TILE_S, game->exit.y * TILE_S);
		game->player.game_won = 1;
	}
}
