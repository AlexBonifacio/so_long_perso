/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:01:32 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/28 16:35:44 by abonifac         ###   ########.fr       */
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
}
static void init_textures(t_txtrs *txtrs)
{
	ft_memset(txtrs, 0, sizeof(t_txtrs));
}

void	init_structs_null(t_game *game)
{
	init_game(game);
	init_textures(&game->txtrs);
	init_player(&game->player);
}
