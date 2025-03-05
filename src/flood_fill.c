/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:00:03 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/05 14:15:41 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	exit_valid(char **map, t_game *game)
{
	int	i;
	int	y;

	i = game->exit.y;
	y = game->exit.x;
	if (map[i - 1][y] != 'G' && map[i + 1][y] != 'G' && map[i][y - 1] != 'G'
		&& map[i][y + 1] != 'G')
	{
		w_error("Map invalid, exit not reachable\n");
		return (0);
	}
	if (count_in_map(map, 'C') > 0)
	{
		w_error("Not all coins are reacheables\n");
		return (0);
	}
	return (1);
}

char	**copy_map(char **map)
{
	int		y;
	char	**new_map;

	y = 0;
	while (map[y])
		y++;
	new_map = malloc(sizeof(char *) * (y + 1));
	if (!new_map)
		return (NULL);
	y = 0;
	while (map[y])
	{
		new_map[y] = ft_strdup(map[y]);
		if (!new_map[y])
		{
			free_tab(new_map);
			return (NULL);
		}
		y++;
	}
	new_map[y] = NULL;
	return (new_map);
}

void	flood_fill_recursive(t_game *game, char **map, int x, int y)
{
	int	count;

	count = 0;
	if (x < 1 || y < 1 || x >= game->map.width_tiles
		|| y >= game->map.height_tiles)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'E'
		|| map[y][x] == 'G')
		return ;
	if (map[y][x] == 'C')
		count++;
	map[y][x] = 'G';
	flood_fill_recursive(game, map, x + 1, y);
	flood_fill_recursive(game, map, x - 1, y);
	flood_fill_recursive(game, map, x, y + 1);
	flood_fill_recursive(game, map, x, y - 1);
}

void	flood_fill(t_game *game)
{
	char	**new_map;

	init_struct(game, &game->player.x, &game->player.y, 'P');
	init_struct(game, &game->exit.x, &game->exit.y, 'E');
	game->map.coins = count_in_map(game->map.map, 'C');
	new_map = copy_map(game->map.map);
	if (!new_map)
	{
		w_error("Error: fail to copy the map\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	flood_fill_recursive(game, new_map, game->player.x, game->player.y);
	if (!exit_valid(new_map, game))
	{
		free_tab(new_map);
		free_game(game);
		exit(EXIT_FAILURE);
	}
	free_tab(new_map);
}
