/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:43:43 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/02 19:09:27 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

typedef struct s_player
{
	int			x;
	int			y;
	int			collected;
	int			game_won;
	int			moves;
}				t_player;

typedef struct s_ennemy
{
	int			x;
	int			y;
	int			frame;
}				t_ennemy;

typedef struct s_exit
{
	int			x;
	int			y;
}				t_exit;

typedef struct s_textures
{
	void		*wall;
	void		*ground;
	void		*player;
	void		*ennemy[4];
	void		*gather;
	void		*exit;
	void		*exit_closed;
	void		*score[10];
}				t_txtrs;

typedef struct s_map
{
	char 	**map;
	int		width;
	int		height;
	int 	coins;
	int 	score_x[3];
	int 	score_y;
} 				t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_ennemy	ennemy;
	t_exit		exit;
	t_txtrs		txtrs;
	t_player	player;
}				t_game;

# define TILE_S 128

void			w_error(char *msg);
int				count_in_map(t_game *game, char c);
int				check_nb_assets(t_game *game);
void			free_game(t_game *game);
void			free_map(t_game *game);
int				map_line_len(char *line);
void			load_digits(t_game *game);
void			find_score_position(t_game *game);
void			update_score(t_game *game, int count);
void			load_walls(t_game *game, int w, int h);
void			load_ground(t_game *game, int w, int h);
void			load_player(t_game *game, int w, int h);
void			load_gather(t_game *game, int w, int h);
void			load_exit(t_game *game, int w, int h);
void			load_assets(t_game *game, int w, int h);
void			render_map(t_game *game);
void			render_player(t_game *game);
void			render_score_handler(t_game *game, int x, int y);
void			render_map_handler(t_game *game, int x, int y);
void			update_map(t_game *game, int old_x, int old_y);
int				check_move(t_game *game, char c);
void			check_move_exit(t_game *game, int old_x, int old_y);
void			player_move(int key, t_game *game);
void			map_checker(t_game *game);
void			init_structs_null(t_game *game);
void			render(t_game *game);
void			load_exit_closed(t_game *game, int w, int h);
int				close_window(t_game *game);
int				key_handler(int key, t_game *game);
void			load_ennemy(t_game *game, int w, int h);
void			fd_error(int fd);
void			free_tab(char **tab);
void			*return_null_free(char **str);
char			**load_map(char *filename);
char			*add_counter(char *line);
void			get_position(t_game *game, char c, int *x, int *y);
void			get_map_size(t_game *game, int *width, int *height);
int				animate_enemies(t_game *game);

#endif