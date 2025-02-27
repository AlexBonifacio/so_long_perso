/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:19:22 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/27 15:06:51 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "libft.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#define TILE_SIZE 128

void load_assets(t_game *game, int w, int h);

void get_map_size(t_game *game, int *width, int *height)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
		y++;
	*height = y * TILE_SIZE;

	x = 0;
	while (game->map[0][x])
		x++;
	*width = x * TILE_SIZE;
}
void render_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
									game->txtrs.ground, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1') // Si c’est un mur
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
										game->txtrs.wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C') // Si c’est un collectible
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
										game->txtrs.gather, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E') // Si c’est la sortie
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
										game->txtrs.exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'U') // Si c’est un unit
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
										game->txtrs.score[0], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'D') // Si c’est un decimal
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
										game->txtrs.score[0], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'H') // Si c’est un hundredth
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
										game->txtrs.score[0], x * TILE_SIZE, y * TILE_SIZE);

			x++;
		}
		y++;
	}
}


void render_player(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.player,
										x * TILE_SIZE, y * TILE_SIZE);
				game->player.x = x;
				game->player.y = y;
				// ft_printf("Player is at: x: %i | y: %i | %c\n", x, y, game->map[x][y]);
			}
			x++;
		}
		y++;
	}
}
char *add_counter(char *line)
{
	int len;
	char *count;
	int i = 4;

	len = map_line_len(line);
	count = malloc(sizeof(char) * (len + 3));
	if (!count)
		return NULL; // gerer dans load map ?
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

char **load_map(char *filename)
{
	int fd;
	char *line;
	char *temp;
	char **map;
	char *old_temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	temp = ft_strdup(""); // Initialise temp à une chaîne vide
	if (!temp)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		old_temp = temp;
		temp = ft_strjoin(temp, line);
		free(old_temp); // Libère l'ancienne mémoire // il faudra aussi liberer les allocs precedentes
		free(line);
		if (!temp) // Vérifie si ft_strjoin a échoué
			return (NULL);
	}
	old_temp = temp;
	line = add_counter(temp);
	temp = ft_strjoin(temp, line);
	if (!temp)
		return NULL;
	free(line);
	free(old_temp);
	ft_printf("%s\n", temp);
	close(fd);
	map = ft_split(temp, '\n');
	free(temp);
	return (map);
}

// Redessiner la carte pour afficher la nouvelle position

void update_map(t_game *game, int old_x, int old_y)
{
	// Effacer l'ancienne position dans la carte en mettant '0'

	game->map[old_y][old_x] = '0';

	// Mettre à jour la nouvelle position avec 'P'
	game->map[game->player.y][game->player.x] = 'P';

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.ground,
							old_x * TILE_SIZE, old_y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txtrs.player,
							game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	render_player(game);
}

int check_move(t_game *game, char c)
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

void check_move_exit(t_game *game, int old_x, int old_y)
{

	if (game->player.game_won)
	{
		ft_printf("🎊 Congratulation ! You won ! 🎊\n");
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("🚫 You are missing coins! (%d/%d)\n",
				  game->player.collected, game->coins);
		game->player.x = old_x;
		game->player.y = old_y;
	}
}

void display_moves(t_game *game)
{
	char *moves_str;

	moves_str = ft_itoa(game->player.moves); // Convertir le nombre en string
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0xFFFFFF, "Mouvements :");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 130, 10, 0xFFFFFF, moves_str);
	free(moves_str); // Libérer la mémoire de ft_itoa
}
void clear_text_area(t_game *game)
{
	int x, y;

	// Dessiner un rectangle de fond pour effacer l'ancien texte
	for (y = 0; y < 20; y++)
		for (x = 0; x < 200; x++)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, 0x000000); // Noir
}

int player_move(int key, t_game *game)
{
	static int count;
	int old_x = game->player.x;
	int old_y = game->player.y;

	// ft_printf("Avant déplacement: x=%d, y=%d, touche=%d\n", game->player.x, game->player.y, key);

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
	if (game->map[game->player.y][game->player.x] == 'C')
		game->player.collected++;
	ft_printf("Move count %i\n", count);
	clear_text_area(game);
	display_moves(game);
	update_map(game, old_x, old_y);
	if (game->player.collected == game->coins)
	{
		game->player.game_won = 1;
	}

	return (0);
}

int close_window(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
int key_handler(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		close_window(game);
	}
	else if (key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down)
		player_move(key, game);

	return (0);
}

void map_checker(t_game *game)
{
	check_nb_assets(game);
}

int main(void)
{

	t_game game;

	int w = TILE_SIZE;
	int h = TILE_SIZE;
	int win_w;
	int win_h;

	game.map = load_map("map.ber");
	if (!game.map)
	{
		ft_printf("Error : fail to load the map.\n");
		free_game(&game);
		return (1);
	}
	map_checker(&game);

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);
	init_player(&game.player);

	get_map_size(&game, &win_w, &win_h);

	game.win_ptr = mlx_new_window(game.mlx_ptr, win_w, win_h, "so_long");
	if (!game.win_ptr)
	{
		free_game(&game);
		return (1);
	}

	load_assets(&game, w, h);

	render_map(&game);
	render_player(&game);
	game.coins = count_in_map(&game, 'C');
	ft_printf("game coins %i\n", game.coins);

	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_key_hook(game.win_ptr, key_handler, &game);

	mlx_loop(game.mlx_ptr);
	mlx_destroy_display(game.mlx_ptr);
	free_game(&game);
}

void load_assets(t_game *game, int w, int h)
{
	game->txtrs.wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/extracted_nature/tile_1_7.xpm", &w, &h);
	if (!game->txtrs.wall)
	{
		ft_printf("Error : fail to load walls\n");
		free_game(game);
		exit(1);
	}
	game->txtrs.ground = mlx_xpm_file_to_image(game->mlx_ptr, "textures/extracted_textures/tile_8_4.xpm", &w, &h);
	if (!game->txtrs.ground)
	{
		ft_printf("Error : fail to load ground\n");
		free_game(game);
		exit(1);
	}
	game->txtrs.gather = mlx_xpm_file_to_image(game->mlx_ptr, "textures/extracted_textures/tile_10_8.xpm", &w, &h);
	if (!game->txtrs.gather)
	{
		ft_printf("Error : fail to load gather\n");
		free_game(game);
		exit(1);
	}
	game->txtrs.player = mlx_xpm_file_to_image(game->mlx_ptr, "textures/extracted_char/tile_1_4.xpm", &w, &h);
	if (!game->txtrs.player)
	{
		ft_printf("Error : fail to load player\n");
		free_game(game);
		exit(1);
	}

	game->txtrs.exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/extracted_floor/tile_10_12.xpm", &w, &h);
	if (!game->txtrs.exit)
	{
		ft_printf("Error : fail to load exit\n");
		free_game(game);
		exit(1);
	}
	load_digits(game);
}

void display_tab(t_game game)
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