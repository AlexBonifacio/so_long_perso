/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ennemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:41:39 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/07 20:19:02 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include "libft.h"

void	init_filenames(char *filenames[])
{
	filenames[0] = "textures/extracted_ennemy/tile_1_1.xpm";
	filenames[1] = "textures/extracted_ennemy/tile_2_1.xpm";
	filenames[2] = "textures/extracted_ennemy/tile_3_1.xpm";
	filenames[3] = "textures/extracted_ennemy/tile_4_1.xpm";
}

void	load_ennemy(t_game *game, int w, int h)
{
	char	*filenames[ENNEMY_FRAMES];
	int		i;

	init_filenames(filenames);
	i = 0;
	while (i < ENNEMY_FRAMES)
	{
		game->txtrs.ennemy[i] = mlx_xpm_file_to_image(game->mlx_ptr,
				filenames[i], &w, &h);
		if (!game->txtrs.ennemy[i])
		{
			ft_free_tab_struct(game->mlx_ptr, (void **)game->txtrs.ennemy, i);
			w_error("Error: fail to load ennemy\n");
			free_game(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	get_position(game, 'V', &game->ennemy.x, &game->ennemy.y);
}
