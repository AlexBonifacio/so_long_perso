/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:01:32 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/04 11:48:30 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	ft_memset(&game->player, 0, sizeof(t_player));
	ft_memset(&game->txtrs, 0, sizeof(t_txtrs));
	ft_memset(&game->ennemy, -1, sizeof(t_ennemy));
	ft_memset(&game->exit, 0, sizeof(t_exit));
}

void	init_structs_null(t_game *game)
{
	init_game(game);
	
}

void	init_player(t_game *game)
{
	int	x;
	int	y;
	
	x = 0;
	while(game->map.map[x])
	{
		y = 0;
		while(game->map.map[x][y])
		{
			if (game->map.map[x][y] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
