/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:35:58 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/27 14:20:51 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	load_digits(t_game *game)
{
	int w;
	int	h;
	char	*filenames[10] = {"textures/score/tile_2_2.xpm", "textures/score/tile_3_2.xpm",
	"textures/score/tile_4_2.xpm", "textures/score/tile_5_2.xpm", "textures/score/tile_6_2.xpm",
	"textures/score/tile_7_2.xpm", "textures/score/tile_8_2.xpm", "textures/score/tile_9_2.xpm",
	"textures/score/tile_10_2.xpm", "textures/score/tile_11_2.xpm"};

	int i = 0;
	while (i < 10)
	{
		game->txtrs.score[i] = mlx_xpm_file_to_image(game->mlx_ptr, filenames[i], &w, &h);
		if (!game->txtrs.score[i])
		{
			ft_printf("Error: fail to load score\n");
			free(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
