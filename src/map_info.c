/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:38:06 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/02 20:29:07 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	count_in_map(t_game *game, char c)
{
	int	count;
	int	i;
	int	y;

	count = 0;
	i = 0;
	y = 0;
	while (game->map.map[i])
	{
		y = 0;
		while (game->map.map[i][y])
		{
			if (game->map.map[i][y] == c)
				count++;
			y++;
		}
		i++;
	}
	return (count);
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
	get_position(game, 'E', &game->exit.x, &game->exit.y);
}

int	check_nb_assets(t_game *game)
{
	if (count_in_map(game, 'P') != 1 || count_in_map(game, 'E') != 1)
	{
		ft_printf("Error: too many players or exit\n");
		free_map(game);
		exit(EXIT_FAILURE);
		return (0);
	}
	return (1);
}
