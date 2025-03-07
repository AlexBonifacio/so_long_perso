/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:38:06 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/07 19:44:50 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	check_map_size(t_game *game)
{
	if (game->map.width_tiles < 3 || game->map.height_tiles < 3)
	{
		w_error("Error: map is too small\n");
		free_map(game);
		exit(EXIT_FAILURE);
	}
}

int	is_valid_char(char c)
{
	return (c == '0' || c == 'E' || c == 'C' || c == '1' || c == 'P'
		|| c == 'V');
}

void	check_invalid_char(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map.height_tiles > y)
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (!is_valid_char(game->map.map[y][x]))
			{
				w_error("Error: invalid character in the map\n");
				free_map(game);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

int	check_nb_assets(t_game *game)
{
	if (count_in_map(game->map.map, 'P') != 1 || count_in_map(game->map.map,
			'E') != 1)
	{
		ft_printf("Error: Something wrong about player or exit\n");
		free_map(game);
		exit(EXIT_FAILURE);
		return (0);
	}
	if (count_in_map(game->map.map, 'C') < 1)
	{
		ft_printf("Error: No coins in the map\n");
		free_map(game);
		exit(EXIT_FAILURE);
		return (0);
	}
	return (1);
}

void	map_checker(t_game *game)
{
	if (!game->map.map)
	{
		w_error("Error: fail to load the map\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	init_map_struct(game);
	check_map_size(game);
	check_nb_assets(game);
	check_map_walls(game);
	check_invalid_char(game);
	flood_fill(game);
}
