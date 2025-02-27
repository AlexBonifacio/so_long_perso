/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:01:32 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/27 16:55:23 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->collected = 0;
	player->game_won = 0;
	player->moves = 0;
}

void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
}
