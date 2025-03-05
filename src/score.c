/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:51:10 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/05 22:17:20 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	init_score_position(t_game *game)
{
	game->map.score_x[0] = -1;
	game->map.score_x[1] = -1;
	game->map.score_x[2] = -1;
	game->map.score_y = -1;
}

void	check_score_init(t_game *game)
{
	if (game->map.score_x[0] == -1 || game->map.score_x[1] == -1
		|| game->map.score_x[2] == -1 || game->map.score_y == -1)
	{
		w_error("Error: missing score in map\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void	find_score_position(t_game *game)
{
	int	x;
	int	y;

	init_score_position(game);
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'H')
			{
				game->map.score_x[0] = x;
				game->map.score_y = y;
			}
			else if (game->map.map[y][x] == 'D')
				game->map.score_x[1] = x;
			else if (game->map.map[y][x] == 'U')
				game->map.score_x[2] = x;
			x++;
		}
		y++;
	}
	check_score_init(game);
}

char	*create_counter_line(int max_len)
{
	char	*counter;
	int		i;

	/*
	** On crée une ligne compteur de la forme :
	** "\nHDU1111...\n" avec max_len '1' après "HDU"
	** La taille totale sera donc max_len + 3 (1 pour '\n' au début, 1 pour chaque lettre "H", "D", "U")
	** et + 2 pour le '\n' final et le '\0'.
	*/
	counter = malloc(sizeof(char) * (max_len + 3));
	if (!counter)
		return (NULL);
	counter[0] = '\n';
	counter[1] = 'H';
	counter[2] = 'D';
	counter[3] = 'U';
	i = 4;
	while (i < max_len + 1)
	{
		counter[i] = '1';
		i++;
	}
	counter[i] = '\n';  // Ajout du retour à la ligne final
	i++;
	counter[i] = '\0';
	return (counter);
}

char	**append_counter_line(char **map, char *counter_line)
{
	char	**new_map;
	int		size;
	int		i;

	/* Calculer la taille de la map */
	size = 0;
	while (map[size])
		size++;
	new_map = malloc(sizeof(char *) * (size + 2)); // +1 pour la nouvelle ligne et +1 pour le NULL final
	if (!new_map)
	{
		// Il faudrait libérer map ici en cas d'erreur
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i++] = counter_line;
	new_map[i] = NULL;
	// On libère le tableau initial (mais pas les chaînes qu'il contient, elles sont transférées)
	free(map);
	return (new_map);
}


void	update_score(t_game *game, int count)
{
	int	u;
	int	d;
	int	h;

	u = count % 10;
	d = (count / 10) % 10;
	h = (count / 100) % 10;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.score[u],
		game->map.score_x[2] * TILE_S, game->map.score_y * TILE_S);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.score[d],
		game->map.score_x[1] * TILE_S, game->map.score_y * TILE_S);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.score[h],
		game->map.score_x[0] * TILE_S, game->map.score_y * TILE_S);
}
