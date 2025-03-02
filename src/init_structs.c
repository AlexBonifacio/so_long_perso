/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:01:32 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/02 19:40:35 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->collected = 0;
	player->game_won = 0;
	player->moves = 0;
}

static void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	ft_memset(&game->txtrs, 0, sizeof(t_txtrs));
	ft_memset(&game->ennemy, 0, sizeof(t_ennemy));
	ft_memset(&game->exit, 0, sizeof(t_exit));
}

void	init_structs_null(t_game *game)
{
	init_game(game);
	init_player(&game->player);
}
