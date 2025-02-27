/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_score_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:51:10 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/27 15:04:35 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_score_position(t_game *game)
{
	int	x;
	int	y;
	
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'H')
			{
				game->score_x[0] = x;
				game->score_y = y;
			}
			else if (game->map[y][x] == 'D')
				game->score_x[1] = x;
			else if (game->map[y][x] == 'U')
				game->score_x[2] = x;
			x++;
		}
		y++;
	}
}
