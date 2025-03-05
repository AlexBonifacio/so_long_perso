/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:58:57 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/05 14:55:55 by abonifac         ###   ########.fr       */
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
	if (game->map.map)
	{
		y = 0;
		while (game->map.map[y])
			free(game->map.map[y++]);
		free(game->map.map);
	}
}

void	ft_free_tab_struct(void *mlx_ptr, void **tab, int size)
{
	if (!tab || !mlx_ptr)
		return ;
	while (size > 0)
	{
		size--;
		mlx_destroy_image(mlx_ptr, tab[size]);
		tab[size] = NULL;
	}
}

static void	free_game_helper(t_game *game)
{
	if (game->txtrs.wall)
		mlx_destroy_image(game->mlx_ptr, game->txtrs.wall);
	if (game->txtrs.ground)
		mlx_destroy_image(game->mlx_ptr, game->txtrs.ground);
	if (game->txtrs.exit)
		mlx_destroy_image(game->mlx_ptr, game->txtrs.exit);
	if (game->txtrs.exit_closed)
		mlx_destroy_image(game->mlx_ptr, game->txtrs.exit_closed);
	if (game->txtrs.player)
		mlx_destroy_image(game->mlx_ptr, game->txtrs.player);
	if (game->txtrs.gather)
		mlx_destroy_image(game->mlx_ptr, game->txtrs.gather);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_map(game);
	if (game->mlx_ptr)
	{
		free_game_helper(game);
		if (game->txtrs.ennemy[0])
			ft_free_tab_struct(game->mlx_ptr, (void **)game->txtrs.ennemy, 4);
		if (game->txtrs.score[0])
			ft_free_tab_struct(game->mlx_ptr, (void **)game->txtrs.score, 10);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(EXIT_FAILURE);
}
