#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

// typedef struct s_data
// {
// 	void		*mlx_ptr; // MLX pointer
// 	void		*win_ptr; // MLX window pointer
// 	void		*textures[5]; // MLX image pointers (on the stack)
// 	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
// }	t_data;

typedef struct s_player
{
	int x;
	int y;
	int collected;
	int	game_won;
	int moves;
} t_player;

typedef struct s_textures
{
	void *wall;
	void *ground;
	void *player;
	void *gather;
	void *exit;
	void *score[10];
} t_txtrs;

typedef struct s_game
{
	void 		*mlx_ptr;
	void 		*win_ptr;
	char 		**map;
	int			coins;
	int			score_x[3];
	int			score_y;
	t_txtrs 	txtrs;
	t_player 	player;
} t_game;

# define TILE_S 128

void	w_error(char *msg);
int	count_in_map(t_game *game, char c);
int	check_nb_assets(t_game *game);
void free_game(t_game *game);
void	free_map(t_game *game);
int	map_line_len(char *line);
void	load_digits(t_game *game);
void	find_score_position(t_game *game);
void	update_score(t_game *game, int count);
void	load_walls(t_game *game, int w, int h);
void	load_ground(t_game *game, int w, int h);
void	load_player(t_game *game, int w, int h);
void	load_gather(t_game *game, int w, int h);
void	load_exit(t_game *game, int w, int h);
void	load_assets(t_game *game, int w, int h);
void	render_map(t_game *game);
void	render_player(t_game *game);
void	render_score_handler(t_game *game, int x, int y);
void	render_map_handler(t_game *game, int x, int y);
void	update_map(t_game *game, int old_x, int old_y);
int	check_move(t_game *game, char c);
void	check_move_exit(t_game *game, int old_x, int old_y);
void	player_move(int key, t_game *game);
void	map_checker(t_game *game);
void	init_structs_null(t_game *game);
void	render(t_game *game);

#endif