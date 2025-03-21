/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:43:43 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/08 18:38:53 by abonifac         ###   ########.fr       */
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
	char		**map;
	int			width;
	int			height;
	int			width_tiles;
	int			height_tiles;
	int			coins;
	int			score_x[3];
	int			score_y;
}				t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	long		dynamic_sleep_time;
	t_map		map;
	t_ennemy	ennemy;
	t_exit		exit;
	t_txtrs		txtrs;
	t_player	player;
}				t_game;

# define TILE_S 128
# define FRAME_RATE 30
# define LOSE_COUNTER 999
# define ENNEMY_FRAMES 4
# define SCORE_FRAMES 10

void			w_error(char *msg);
int				count_in_map(char **map, char c);
int				check_nb_assets(t_game *game);
void			free_game(t_game *game);
void			free_map(t_game *game);
int				map_line_len(char *line);
void			find_score_position(t_game *game);
void			update_score(t_game *game, int count);
void			load_digits(t_game *game);
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
void			render(t_game *game);
void			update_map(t_game *game, int old_x, int old_y);
int				check_move(t_game *game, char c);
void			check_move_exit(t_game *game, int old_x, int old_y);
void			player_move(int key, t_game *game);
void			map_checker(t_game *game);
void			init_structs_null(t_game *game);
void			load_exit_closed(t_game *game, int w, int h);
int				close_window(t_game *game);
int				key_handler(int key, t_game *game);
void			load_ennemy(t_game *game, int w, int h);
void			fd_error(int fd, char *string);
void			free_tab(char **tab);
void			*return_null_free(char **str);
char			**load_map(char *filename);
char			*add_counter(char *line);
char			**add_counter_to_map(char **map);
void			get_position(t_game *game, char c, int *x, int *y);
void			get_map_size(t_game *game);
int				animate_enemies(t_game *game);
long long		current_time(void);
int				measure_cpu_speed(void);
long			init_dynamic_sleep(void);
int				game_loop(t_game *game);
void			display_tab(t_game game);
void			init_struct(t_game *game, int *x, int *y, char c);
void			init_map_struct(t_game *game);
void			flood_fill(t_game *game);
void			flood_fill_recursive(t_game *game, char **map, int x, int y);
void			display_map(char **map);
int				is_valid_char(char c);
void			check_invalid_char(t_game *game);
void			check_map_size(t_game *game);
void			check_map_walls(t_game *game);
void			map_walls_horiz(t_game *game);
void			map_walls_vert(t_game *game);
void			map_walls_error(t_game *game);
int				exit_valid(char **map, t_game *game);
int				check_arg(int argc, char *argv[]);
void			ft_free_tab_struct(void *mlx_ptr, void **tab, int size);
char			*read_file_content(char *filename);
int				get_max_len(char **map);
char			*create_counter_line(char *string);
char			**append_counter_line(char **map, char *counter_line);
int				ft_strlen_n(const char *s);
void			check_double_n(char *temp);
void			check_line(char **map);
void			ft_strlen_n_error(char *file_content);
int				ft_loser(t_game *game, int count);

#endif