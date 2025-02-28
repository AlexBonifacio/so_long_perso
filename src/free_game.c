/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:58:57 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/28 16:28:56 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>

void	free_map(t_game *game)
{
	int	y;

	y = 0;
	if (game->map)
	{
		y = 0;
		while (game->map[y])
			free(game->map[y++]);
		free(game->map);
	}
}

void	ft_free_score(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10 && game->txtrs.score[i])
	{
		mlx_destroy_image(game->mlx_ptr, game->txtrs.score[i]);
		game->txtrs.score[i] = NULL;
		i++;
	}
	return ;
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_map(game);
	if (game->mlx_ptr)
	{
		if (game->txtrs.wall)
			mlx_destroy_image(game->mlx_ptr, game->txtrs.wall);
		if (game->txtrs.ground)
			mlx_destroy_image(game->mlx_ptr, game->txtrs.ground);
		if (game->txtrs.exit)
			mlx_destroy_image(game->mlx_ptr, game->txtrs.exit);
		if (game->txtrs.player)
			mlx_destroy_image(game->mlx_ptr, game->txtrs.player);
		if (game->txtrs.gather)
			mlx_destroy_image(game->mlx_ptr, game->txtrs.gather);
		if (game->txtrs.score[0])
			ft_free_score(game);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(EXIT_FAILURE);
}
