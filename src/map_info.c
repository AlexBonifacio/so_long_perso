/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:38:06 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/04 12:44:55 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int count_in_map(t_game *game, char c)
{
	int count;
	int i;
	int y;

	count = 0;
	i = 0;
	y = 0;
	while (game->map.map[i])
	{
		y = 0;
		while (game->map.map[i][y])
		{
			if (game->map.map[i][y] == c)
				count++;
			y++;
		}
		i++;
	}
	return (count);
}

void map_walls_error(t_game *game)
{
	w_error("Error: map is not closed\n");
	free_map(game);
	exit(EXIT_FAILURE);
}
void map_walls_horiz(t_game *game)
{
	int height;
	int y;

	height = game->map.height_tiles - 1;
	y = 0;
	while (game->map.map[0][y])
	{
		if (game->map.map[0][y] != '1')
			map_walls_error(game);
		y++;
	}
	y = 0;
	while (game->map.map[height][y])
	{
		if (game->map.map[height][y] != '1')
			map_walls_error(game);
		y++;
	}
}

void map_walls_vert(t_game *game)
{
	int width;
	int x;

	width = game->map.width_tiles - 1;
	x = 0;
	while (game->map.map[x] && x < game->map.height_tiles)
	{
		if (game->map.map[x][0] != '1')
			map_walls_error(game);
		x++;
	}
	x = 0;
	while (game->map.map[x] && x < game->map.height_tiles)
	{
		if (game->map.map[x][width] != '1')
			map_walls_error(game);
		x++;
	}
}

void check_map_walls(t_game *game)
{
	map_walls_horiz(game);
	map_walls_vert(game);
}

void check_map_size(t_game *game)
{
	if (game->map.width_tiles < 3 || game->map.height_tiles < 3)
	{
		w_error("Error: map is too small\n");
		free_map(game);
		exit(EXIT_FAILURE);
	}
}

void check_map_rectangle(t_game *game)
{
	if (game->map.width == game->map.height_tiles)
	{
		w_error("Error: map is not a rectangle\n");
		free_map(game);
		exit(EXIT_FAILURE);
	}
}

int is_valid_char(char c)
{
	return (c == '0' || c == 'E' || c == 'C' || c == '1' || c == 'P' || c == 'V');
}

void check_invalid_char(t_game *game)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (game->map.height_tiles > y)
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (!is_valid_char(game->map.map[y][x]))
			{
				w_error("Error: invalid character in the map\n");
				free_map(game);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}
void init_map_size(t_game *game)
{
	game->map.width_tiles = game->map.width / TILE_S;
	game->map.height_tiles = (game->map.height - TILE_S) / TILE_S;
}
void flood_fill(t_game *game);

void flood_fill_recursive(t_game *game, char **map, int x, int y)
{
	if (x < 1 || y < 1 || x >= game->map.width_tiles || y >= game->map.height_tiles)
		return ;
	if (map[x][y + 1] == '0' || map[x][y+1] == 'C')
	{
		map[x][y + 1] = 'P';
		flood_fill_recursive(game, map, x, y + 1);
	}
	if (map[x][y - 1] == '0')
	{
		map[x][y + 1] = 'P';

		flood_fill_recursive(game, map, x, y - 1);
	}
	if (map[x + 1][y] == '0')
	{
		map[x][y + 1] = 'P';

		flood_fill_recursive(game, map, x + 1, y);
	}
	if (map[x - 1][y] == '0')
	{
		map[x][y + 1] = 'P';

		flood_fill_recursive(game, map, x - 1, y);
	}
}

void display_map(char **map)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			ft_printf("%c", map[i][y]);
			y++;
		}
		i++;
		ft_printf("\n");
	}
}

char	**copy_map(char **map)
{
	int y;
	char **new_map;

	y = 0;
	while (map[y])
		y++;
	y--;
	new_map = malloc(sizeof(char *) * (y + 1));
	if (!new_map)
		return (NULL);
	while(y > 0)
	{
		new_map[y] = ft_strdup(map[y]);
		y--;
	}
	new_map[y] = NULL;
	return (new_map);
}
void flood_fill(t_game *game)
{
	char **map;

	init_player(game);
	map = copy_map(game->map.map);
	display_map(map);

//	flood_fill_recursive(game, map, game->player.x, game->player.y);
}

void map_checker(t_game *game)
{
	get_map_size(game);
	init_map_size(game);
	flood_fill(game);
	if (!game->map.map)
	{
		w_error("Error: fail to load the map\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	check_map_size(game);
	check_nb_assets(game);
	check_map_rectangle(game);
	check_map_walls(game);
	check_invalid_char(game);
	find_score_position(game);
	get_position(game, 'E', &game->exit.x, &game->exit.y);
}

int check_nb_assets(t_game *game)
{
	if (count_in_map(game, 'P') != 1 || count_in_map(game, 'E') != 1)
	{
		ft_printf("Error: Something wrong about player or exit\n");
		free_map(game);
		exit(EXIT_FAILURE);
		return (0);
	}
	if (count_in_map(game, 'C') < 1)
	{
		ft_printf("Error: No coins in the map\n");
		free_map(game);
		exit(EXIT_FAILURE);
		return (0);
	}
	return (1);
}
