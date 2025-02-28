/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:19:22 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/28 17:32:13 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	load_assets(t_game *game, int w, int h);

void	get_map_size(t_game *game, int *width, int *height)
{
	int	x;
	int	y;

	if ((!game->map) || (!game->map[0]))
	{
		w_error("Error: map is empty\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	
	y = 0;
	while (game->map[y])
		y++;
	*height = y * TILE_S;
	x = 0;
	while (game->map[0][x])
		x++;
	*width = x * TILE_S;
}
void	render_score_handler(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'U') // Si c’est un unit
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->txtrs.score[0], x * TILE_S, y * TILE_S);
	else if (game->map[y][x] == 'D') // Si c’est un decimal
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->txtrs.score[0], x * TILE_S, y * TILE_S);
	else if (game->map[y][x] == 'H') // Si c’est un hundredth
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->txtrs.score[0], x * TILE_S, y * TILE_S);
}
void	render_map_handler(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.ground, x
		* TILE_S, y * TILE_S);
	if (game->map[y][x] == '1') // Si c’est un mur
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.wall,
			x * TILE_S, y * TILE_S);
	else if (game->map[y][x] == 'C') // Si c’est un collectible
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->txtrs.gather, x * TILE_S, y * TILE_S);
	else if (game->map[y][x] == 'E') // Si c’est la sortie
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.exit,
			x * TILE_S, y * TILE_S);
	render_score_handler(game, x, y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_map_handler(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->txtrs.player, x * TILE_S, y * TILE_S);
				game->player.x = x;
				game->player.y = y;
			}
			x++;
		}
		y++;
	}
}
char	*add_counter(char *line)
{
	int		len;
	char	*count;
	int		i;

	i = 4;
	len = map_line_len(line);
	count = malloc(sizeof(char) * (len + 3));
	if (!count)
		return (NULL); // gerer dans load map ?
	count[0] = '\n';
	count[1] = 'H';
	count[2] = 'D';
	count[3] = 'U';
	while (i < len + 1)
	{
		count[i] = '1';
		i++;
	}
	count[i] = '\n';
	i++;
	count[i] = '\0';
	return (count);
}

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

void	*fill_temp(char *temp, char *line, int fd)
{
	char	*old_temp;

	old_temp = NULL;
	while ((line = get_next_line(fd)))
	{
		old_temp = temp;
		temp = ft_strjoin(temp, line);
		free(old_temp);
		free(line);
		if (!temp)
			return (NULL);
	}
	line = add_counter(temp);
	if (!line)
		return (return_null_free(&temp));
	old_temp = temp;
	temp = ft_strjoin(temp, line);
	free(line);
	free(old_temp);
	if (!temp)
		return (NULL);
	return (temp);
}

char	**load_map(char *filename)
{
	int		fd;
	char	*line;
	char	*temp;
	char	**map;

	fd = open(filename, O_RDONLY);
	fd_error(fd);
	line = NULL;
	temp = ft_strdup("");
	if (!temp)
		return (NULL); 
	temp = fill_temp(temp, line, fd);
	if (!temp)
		return (NULL);
	close(fd);
	map = ft_split(temp, '\n');
	free(temp);
	return (map);
}

// Redessiner la carte pour afficher la nouvelle position

void	update_map(t_game *game, int old_x, int old_y)
{
	// Effacer l'ancienne position dans la carte en mettant '0'
	game->map[old_y][old_x] = '0';
	// Mettre à jour la nouvelle position avec 'P'
	game->map[game->player.y][game->player.x] = 'P';
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.ground,
		old_x * TILE_S, old_y * TILE_S);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.player,
		game->player.x * TILE_S, game->player.y * TILE_S);
	render_player(game);
}

int	check_move(t_game *game, char c)
{
	if (game->map[game->player.y][game->player.x + 1] != '1' && c == 'r')
		return (1);
	else if (game->map[game->player.y][game->player.x - 1] != '1' && c == 'l')
		return (1);
	else if (game->map[game->player.y - 1][game->player.x] != '1' && c == 'u')
		return (1);
	else if (game->map[game->player.y + 1][game->player.x] != '1' && c == 'd')
		return (1);
	return (0);
}

void	check_move_exit(t_game *game, int old_x, int old_y)
{
	if (game->player.game_won)
	{
		ft_printf("🎊 Congratulation ! You won ! 🎊\n");
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("🚫 You are missing coins! (%d/%d)\n", game->player.collected,
			game->coins);
		game->player.x = old_x;
		game->player.y = old_y;
	}
}

void	player_move(int key, t_game *game)
{
	static int	count;
	int			old_x;
	int			old_y;

	old_x = game->player.x;
	old_y = game->player.y;
	// Vérifier si la case où on veut aller n'est pas un mur ('1')
	if (key == XK_Left && check_move(game, 'l'))
		game->player.x--;
	else if (key == XK_Right && check_move(game, 'r'))
		game->player.x++;
	else if (key == XK_Up && check_move(game, 'u'))
		game->player.y--;
	else if (key == XK_Down && check_move(game, 'd'))
		game->player.y++;
	if (game->map[game->player.y][game->player.x] == 'E')
		check_move_exit(game, old_x, old_y);
	count++;
	update_score(game, count);
	if (game->map[game->player.y][game->player.x] == 'C')
		game->player.collected++;
	ft_printf("Move count %i\n", count);
	update_map(game, old_x, old_y);
	if (game->player.collected == game->coins)
	{
		game->player.game_won = 1;
	}
}

int	close_window(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
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

void	map_checker(t_game *game)
{
	if (!game->map)
	{
		w_error("Error: fail to load the map\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	check_nb_assets(game);
	find_score_position(game);
}



void	render(t_game *game)
{
	load_assets(game, TILE_S, TILE_S);
	render_map(game);
	render_player(game);
}
int	main(void)
{
	t_game	game;
	int		win_w;
	int		win_h;

	init_structs_null(&game);
	game.map = load_map("map.ber");
	map_checker(&game);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		free_game(&game);
	get_map_size(&game, &win_w, &win_h);
	game.win_ptr = mlx_new_window(game.mlx_ptr, win_w, win_h, "so_long");
	if (!game.win_ptr)
		free_game(&game);
	render(&game);
	game.coins = count_in_map(&game, 'C');
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, key_handler, &game);
	mlx_loop(game.mlx_ptr);
	mlx_destroy_display(game.mlx_ptr);
	free_game(&game);
}


void	load_assets(t_game *game, int w, int h)
{
	load_walls(game, w, h);
	load_ground(game, w, h);
	load_player(game, w, h);
	load_gather(game, w, h);
	load_exit(game, w, h);
	load_digits(game);
}

void	display_tab(t_game game)
{
	int i = 0;
	int y = 0;
	while (game.map[i])
	{
		y = 0;
		while (game.map[i][y])
		{
			ft_printf("%c", game.map[i][y]);
			y++;
		}
		i++;
		ft_printf("\n");
	}
}