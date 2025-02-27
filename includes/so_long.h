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

void	ft_print_error(void);
int	count_in_map(t_game *game, char c);
int	check_nb_assets(t_game *game);
void free_game(t_game *game);
void	free_map(t_game *game);
void	init_player(t_player *player);
int	map_line_len(char *line);
void	load_digits(t_game *game);
void	find_score_position(t_game *game);

#endif