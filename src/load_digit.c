/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:35:58 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/06 19:44:10 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

static void	init_filenames(char *filenames[])
{
	filenames[0] = "textures/score/tile_2_2.xpm";
	filenames[1] = "textures/score/tile_3_2.xpm";
	filenames[2] = "textures/score/tile_4_2.xpm";
	filenames[3] = "textures/score/tile_5_2.xpm";
	filenames[4] = "textures/score/tile_6_2.xpm";
	filenames[5] = "textures/score/tile_7_2.xpm";
	filenames[6] = "textures/score/tile_8_2.xpm";
	filenames[7] = "textures/score/tile_9_2.xpm";
	filenames[8] = "textures/score/tile_10_2.xpm";
	filenames[9] = "textures/score/tile_11_2.xpm";
}

void	load_digits(t_game *game)
{
	int		w;
	int		h;
	int		i;
	char	*filenames[10];

	init_filenames(filenames);
	i = 0;
	while (i < 10)
	{
		game->txtrs.score[i] = mlx_xpm_file_to_image(game->mlx_ptr,
				filenames[i], &w, &h);
		if (!game->txtrs.score[i])
		{
			w_error("Error: fail to load score\n");
			ft_free_tab_struct(game->mlx_ptr, (void **)game->txtrs.score, i);
			free_game(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
