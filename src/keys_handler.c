/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:28:04 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/02 19:40:49 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

int	key_handler(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		close_window(game);
	}
	else if (key == XK_Left || key == XK_Right || key == XK_Up
		|| key == XK_Down)
		player_move(key, game);
	return (0);
}

int	close_window(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
