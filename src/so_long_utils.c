/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:43:11 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/05 14:10:20 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	fd_error(int fd)
{
	if (fd < 0)
	{
		w_error("Error: fail to open the map\n");
		exit(EXIT_FAILURE);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	*return_null_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

void	get_position(t_game *game, char c, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == c)
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_map_size(t_game *game)
{
	int	x;
	int	y;

	if ((!game->map.map) || (!game->map.map[0]))
	{
		w_error("Error: map is empty\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	y = 0;
	while (game->map.map[y])
		y++;
	game->map.height = y * TILE_S;
	x = 0;
	while (game->map.map[0][x])
		x++;
	game->map.width = x * TILE_S;
}
