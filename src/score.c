/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:51:10 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/02 19:55:31 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	init_score_position(t_game *game)
{
	game->map.score_x[0] = -1;
	game->map.score_x[1] = -1;
	game->map.score_x[2] = -1;
	game->map.score_y = -1;
}

void	check_score_init(t_game *game)
{
	if (game->map.score_x[0] == -1 || game->map.score_x[1] == -1
		|| game->map.score_x[2] == -1 || game->map.score_y == -1)
	{
		w_error("Error: missing score in map\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void	find_score_position(t_game *game)
{
	int	x;
	int	y;

	init_score_position(game);
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'H')
			{
				game->map.score_x[0] = x;
				game->map.score_y = y;
			}
			else if (game->map.map[y][x] == 'D')
				game->map.score_x[1] = x;
			else if (game->map.map[y][x] == 'U')
				game->map.score_x[2] = x;
			x++;
		}
		y++;
	}
	check_score_init(game);
}

char	*add_counter(char *line)
{
	int		len;
	char	*count;
	int		i;

	i = 4;
	len = map_line_len(line);
	count = malloc(sizeof(char) * (len + 3));
	if (!count)
		return (NULL);
	count[0] = '\n';
	count[1] = 'H';
	count[2] = 'D';
	count[3] = 'U';
	while (i < len + 1)
	{
		count[i] = '1';
		i++;
	}
	count[i] = '\n';
	i++;
	count[i] = '\0';
	return (count);
}

void	update_score(t_game *game, int count)
{
	int	u;
	int	d;
	int	h;

	u = count % 10;
	d = (count / 10) % 10;
	h = (count / 100) % 10;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.score[u],
		game->map.score_x[2] * TILE_S, game->map.score_y * TILE_S);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.score[d],
		game->map.score_x[1] * TILE_S, game->map.score_y * TILE_S);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.score[h],
		game->map.score_x[0] * TILE_S, game->map.score_y * TILE_S);
}
